<?php
/**
 * @file
 * Admin related backed for item viewer.
 *
 */

/**
 * Admin page menu callback.
 *
 * @return
 *   Admin form.
 */
function ding_item_viewer_admin_page() {
  drupal_add_js(drupal_get_path('module', 'ding_item_viewer') . '/js/ding_item_viewer.admin.js');
  variable_set('ding_item_viewer_search_queries_hidden', array());

  return drupal_get_form('ding_item_viewer_admin_form');
}

/**
 * Search queries admin form.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 *
 * @return
 *   Form structure.
 */
function ding_item_viewer_admin_form($form, &$form_state) {
  $searches_num = !empty($form_state['values']['num_searches']) ? $form_state['values']['num_searches'] : 0;
  $clicked_btn = '';
  $remove_btn = '';
  $hidden = variable_get('ding_item_viewer_search_queries_hidden', array());

  if (isset($form_state['clicked_button'])) {
    $clicked_btn = $form_state['clicked_button']['#name'];

    // Get a clicked 'remove' button
    foreach ($form_state['buttons'] as $k => $v) {
      if ($v['#name'] == $clicked_btn) {
        if (preg_match('/edit-remove/', $v['#id'])) {
          $remove_btn = $k;
          $hidden[] = $remove_btn;
          variable_set('ding_item_viewer_search_queries_hidden', $hidden);
          break;
        }
      }
    }
  }

  $form['browsebar'] = array(
    '#type' => 'fieldset',
    '#title' => 'Searches',
  );

  // Get current saved queries.
  $searches = variable_get('ding_item_viewer_search_queries', array());

  $i = 0;
  $c = 1;

  // Display saved queries.
  if (isset($searches[0]['title'])) {
    $c = count($searches);
    for (; $i < $c; $i++) {
      $form['browsebar']['ting_searches']['search_' . $i] = ding_item_viewer_query_form($searches[$i], $i);
    }
  }

  // Whether add a new query field.
  if ($clicked_btn == 'add_query') {
    $searches_num++;
  }

  for (; $i < $searches_num + $c; $i++) {
    $unsubmitted = array();
    // Maybe prev field had some data in it...
    if (isset($form_state['input']['title'][$i])) {
      $unsubmitted = array(
        'title' => $form_state['input']['title'][$i],
        'subtitle' => $form_state['input']['subtitle'][$i],
        'query' => $form_state['input']['query'][$i],
      );
    }

    $form['browsebar']['ting_searches']['search_' . $i] = ding_item_viewer_query_form($unsubmitted, $i);
  }

  // Hide removed fields.
  for ($i = 0; $i < $searches_num + $c; $i++) {
    if (in_array($i, $hidden)) {
      // Hide title, used to sort needed queries when saving
      $form['browsebar']['ting_searches']['search_' . $i]['title[]']['#value'] = '';
      $form['browsebar']['ting_searches']['search_' . $i]['#prefix'] = '<div class="search-query-hidden">';
      $form['browsebar']['ting_searches']['search_' . $i]['#suffix'] = '</div>';
    }
  }

  // Keep track of query fields count.
  $form['browsebar']['num_searches'] = array(
    '#type' => 'hidden',
    '#value' => $searches_num,
  );

  // Ajaxified button for new fields.
  $form['browsebar']['new_search_browsebar_button'] = array(
    '#type' => 'button',
    '#value' => 'Add another',
    '#name' => 'add_query',
    '#ajax' => array(
      'callback' => 'ding_item_viewer_admin_form_ajaxify',
      'wrapper' => 'ting-search-browsebar-queries',
      'method' => 'replace',
      'effect' => 'fade'
    ),
  );

  $form['browsebar']['ding_item_viewer_item_limit'] = array(
    '#type' => 'textfield',
    '#title' => t('Item limit'),
    '#description' => t('The number of items to be returned in search result.'),
    '#default_value' => variable_get('ding_item_viewer_item_limit', 24)
  );

  $form['browsebar']['ding_item_viewer_cache_ttl'] = array(
    '#type' => 'textfield',
    '#title' => t('Cache TTL'),
    '#description' => t('How many hours the cache lives.'),
    '#default_value' => variable_get('ding_item_viewer_cache_ttl', 1)
  );

  // Wrap the form, due to draggable items renewal.
  $form['#prefix'] = '<div id="ting-search-browsebar-queries">';
  $form['#suffix'] = '</div>';
  // Custom themer, mainly used for dragable table creation.
  $form['#theme'] = array('ding_item_viewer_admin_form');
  // Custom form submit handler.
  $form['#submit'] = array('ding_item_viewer_search_submit');

  return system_settings_form($form);
}

/**
 * AJAX responder for field addition/removal fields.
 *
 * @param $form
 *   Form.
 *
 * @return
 *   Changed field to be updated.
 */
function ding_item_viewer_admin_form_ajaxify($form, &$form_state) {
  return $form;
}

/**
 * Theme the queries form, mainly adding a table drag-n-drop feature.
 *
 * @param $variables
 *   Theme related variables.
 *
 * @return
 *   Themed form output.
 */
function theme_ding_item_viewer_admin_form($variables) {
  $form = $variables['form'];
  drupal_add_tabledrag('ting-search-item_viewer-admin-sort', 'order', 'sibling', 'sort');

  $header = array('Searches', '');
  $rows = array();
  foreach (element_children($form['browsebar']['ting_searches']) as $key) {
    // Add class to group weight fields for drag and drop.
    $form['browsebar']['ting_searches'][$key]['sort[]']['#attributes']['class'][] = 'sort';

    // Get sort element.
    $sort = $form['browsebar']['ting_searches'][$key]['sort[]'];
    unset($form['browsebar']['ting_searches'][$key]['sort[]']);

    // Build rows.
    $classes = array('draggable');
    if (isset($form['browsebar']['ting_searches'][$key]['#prefix'])) {
      $classes[] = 'search-query-hidden';
    }

    $rows[] = array(
      'data' => array(
        drupal_render($form['browsebar']['ting_searches'][$key]),
        drupal_render($sort)
      ),
      'class' => $classes
    );
  }

  $table_vars = array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'ting-search-item_viewer-admin-sort'),
    'caption' => '',
    'colgroups' => array(),
    'sticky' => FALSE,
    'empty' => 'EMPTY'
  );
  $output = theme_table($table_vars);

  // Render remaining elements.
  $output .= drupal_render_children($form);

  return $output;
}

/**
 * Form part, describing query fields.
 *
 * @param $item
 *   Values for existing query.
 *
 * @return
 *   Fields structure.
 */
function ding_item_viewer_query_form($item = array(), $index = 0) {
  $form = array();

  $form['sort[]'] = array(
    '#type' => 'weight',
    '#delta' => 5,
    '#default_value' => 0,
    '#value' => 0,
    '#attributes' => array(
      'class' => array(
        'sort-hidden'
      )
    ),
  );

  $form['title[]'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('The title of the search is used for the tab in the browsebar. Keep it short.'),
    '#default_value' => isset($item['title']) ? $item['title'] : '',
    '#prefix' => '<div class="search-item_viewer-query">',
  );

  $form['subtitle[]'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('The subtitle displayed next to the search results.'),
    '#default_value' => isset($item['subtitle']) ? $item['subtitle'] : '',
  );

  $form['query[]'] = array(
    '#type' => 'textfield',
    '#title' => t('Query'),
    '#maxlength' => 2048,
    '#description' => t('The query to display search results for.'),
    '#default_value' => isset($item['query']) ? $item['query'] : '',
  );

  $form['remove[]'] = array(
    '#type' => 'button',
    '#value' => t('Remove'),
    '#name' => 'remove_' . $index,
    '#attributes' => array(
      'class' => array(
        'remove'
      )
    ),
    '#suffix' => '</div><div class="clear"></div>',
    '#ajax' => array(
      'callback' => 'ding_item_viewer_admin_form_ajaxify',
      'wrapper' => 'ting-search-browsebar-queries',
      'method' => 'replace',
      'effect' => 'fade'
    ),
  );

  return $form;
}

/**
 * Submit handler for admin backend queries form.
 *
 * @param $form
 *   Form.
 * @param $form_state
 *   Form state.
 */
function ding_item_viewer_search_submit($form, &$form_state) {
  $c = count($form_state['input']['title']);
  $searches = array();
  $search_items = array();

  for ($i = 0; $i < $c; $i++) {
    // Make an array for saving, ignoring queries w/o title.
    $title = trim($form_state['input']['title'][$i]);
    $subtitle = trim($form_state['input']['subtitle'][$i]);
    $query = trim($form_state['input']['query'][$i]);

    if (!empty($title) && !empty($query)) {
      $searches[] = array(
        'title' => $title,
        'subtitle' => $subtitle,
        'query' => $query
      );
    }
  }

  // Save the queries as a persistent variable.
  variable_set('ding_item_viewer_search_queries', $searches);

  // Make ting search requests.
  // browsebar_do_request();
}

/**
 * Validate settings submission.
 */
function ding_item_viewer_admin_form_validate($form, &$form_state) {
  $limit = $form_state['values']['ding_item_viewer_item_limit'];
  $cache_ttl = $form_state['values']['ding_item_viewer_cache_ttl'];
  if (!is_numeric($limit)) {
    form_set_error('ding_item_viewer_item_limit', t('Please enter a valid number.'));
  }

  if (!is_numeric($cache_ttl)) {
    form_set_error('ding_item_viewer_cache_ttl', t('Please enter a valid number.'));
  }
}
