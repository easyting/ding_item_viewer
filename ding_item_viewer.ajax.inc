<?php
/**
 * @file
 * AJAX handler and all related functions.
 */

/**
 * AJAX handler.
 */
function ding_item_viewer_ajax() {
  $response = array(
    'status' => 'OK',
    'data' => array(),
    'error' => '',
  );

  $response['data']['tabs'] = ding_item_viewer_build_tabs();
  $response['data']['content'] = theme('item_viewer_content');
  $response['data']['items'] = ding_item_viewer_build_data();

  drupal_json_output($response);
}


/**
 * Build tabs for item viewer.
 *
 * @return string
 *   Tabs layout markup.
 */
function ding_item_viewer_build_tabs() {
  $queries = variable_get('ding_item_viewer_search_queries');

  $tabs = '';

  if (is_array($queries)) {
    foreach ($queries as $k => $query) {
      $tabs .= theme('item_viewer_tab_single', array('tab_index' => $k, 'tab_title' => $query['title']));
    }
  }

  return theme('item_viewer_tabs', array('tabs' => $tabs));
}


/**
 * Build ting related data.
 *
 * This entry fetches all needed objects and outputs the result as a json string
 * into JS script for further use.
 */
function ding_item_viewer_build_data() {
  $queries = variable_get('ding_item_viewer_search_queries');
  $count = variable_get('ding_item_viewer_item_limit', 24);
  $sort = variable_get('ding_item_viewer_item_sorting', '');
  // Cache time in hours.
  $ttl = variable_get('ding_item_viewer_cache_ttl', 0) * 3600;

  $result = array();

  if (is_array($queries)) {
    $tab = 0;
    foreach ($queries as $query) {
      $cid = ding_item_viewer_generate_cache_id($query['query']);
      $cache = cache_get($cid);

      if (!$cache) {
        $objects = ding_item_viewer_get_objects($query['query'], $count, FALSE, $sort);
        $items = array();
        foreach($objects as $item) {
          $build = ting_object_view($item, 'ding_item_viewer_small');
          $small = drupal_render($build);
          $build = ting_object_view($item, 'ding_item_viewer_big');
          $big = drupal_render($build);
          $items[$item->localId] = array(
            'small' => $small,
            'big' => $big,
          );
        }

        // Cache rendered items.
        cache_set($cid, $items, 'cache', REQUEST_TIME + $ttl);
      }
      else {
        $items = $cache->data;
      }
      $result[$tab] = $items;
      $tab++;
    }
  }

  return $result;
}
