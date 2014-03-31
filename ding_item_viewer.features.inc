<?php
/**
 * @file
 * ding_item_viewer.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function ding_item_viewer_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_field_default_fields_alter().
 */
function ding_item_viewer_field_default_fields_alter(&$data) {
  if (isset($data['ting_object-ting_object-ding_availability_holdings'])) {
    $data['ting_object-ting_object-ding_availability_holdings']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '30',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ding_availability_holdings']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ding_entity_buttons'])) {
    $data['ting_object-ting_object-ding_entity_buttons']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'hidden',
      'module' => 'ding_entity_buttons_settings',
      'settings' => array(
        'entity_action_active_buttons' => array(
          'ding_bookmark' => 0,
          'ding_reservation' => 'ding_reservation',
          'ting_relation' => 'ting_relation',
          'ting_sfx' => 'ting_sfx',
        ),
      ),
      'type' => 'ding_entity_buttons_filtered',
      'weight' => '38',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ding_entity_buttons']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '23',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ding_periodical_issues'])) {
    $data['ting_object-ting_object-ding_periodical_issues']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '27',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_abstract'])) {
    $data['ting_object-ting_object-ting_abstract']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'hidden',
      'module' => 'ding_item_viewer',
      'settings' => array(
        'trim_length' => '400',
      ),
      'type' => 'ting_abstract_ding_item_viewer',
      'weight' => '35',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ting_abstract']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '34',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_author'])) {
    $data['ting_object-ting_object-ting_author']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'hidden',
      'module' => 'ding_item_viewer',
      'settings' => array(),
      'type' => 'ting_author_ding_item_viewer',
      'weight' => '34',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ting_author']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'hidden',
      'module' => 'ding_item_viewer',
      'settings' => array(),
      'type' => 'ting_author_ding_item_viewer',
      'weight' => '2',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_cover'])) {
    $data['ting_object-ting_object-ting_cover']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'hidden',
      'module' => 'ding_item_viewer',
      'settings' => array(
        'image_style' => 'ding_item_viewer_image_big',
      ),
      'type' => 'ting_cover_ding_item_viewer',
      'weight' => '1',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ting_cover']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'hidden',
      'module' => 'ting_covers',
      'settings' => array(
        'image_style' => 'ding_item_viewer_image_small',
      ),
      'type' => 'ting_cover_default',
      'weight' => '0',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_age'])) {
    $data['ting_object-ting_object-ting_details_age']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '22',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ting_details_age']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '21',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_audience'])) {
    $data['ting_object-ting_object-ting_details_audience']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '0',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_classification'])) {
    $data['ting_object-ting_object-ting_details_classification']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '35',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_description'])) {
    $data['ting_object-ting_object-ting_details_description']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '10',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_extent'])) {
    $data['ting_object-ting_object-ting_details_extent']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '6',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_format'])) {
    $data['ting_object-ting_object-ting_details_format']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '43',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_genre'])) {
    $data['ting_object-ting_object-ting_details_genre']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '41',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_isbn'])) {
    $data['ting_object-ting_object-ting_details_isbn']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '8',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ting_details_isbn']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '7',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_language'])) {
    $data['ting_object-ting_object-ting_details_language']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '42',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_details_subjects'])) {
    $data['ting_object-ting_object-ting_details_subjects']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'inline',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '3',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_subjects'])) {
    $data['ting_object-ting_object-ting_subjects']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'inline',
      'module' => 'ding_item_viewer',
      'settings' => array(),
      'type' => 'ting_subjects_ding_item_viewer',
      'weight' => '36',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-ting_title'])) {
    $data['ting_object-ting_object-ting_title']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'hidden',
      'module' => 'ting',
      'settings' => array(
        'link_type' => 'none',
      ),
      'type' => 'ting_title_default',
      'weight' => '0',
    ); /* WAS: '' */
    $data['ting_object-ting_object-ting_title']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'hidden',
      'module' => 'ting',
      'type' => 'ting_title_default',
      'weight' => '1',
    ); /* WAS: '' */
  }
  if (isset($data['ting_object-ting_object-voxb_rating'])) {
    $data['ting_object-ting_object-voxb_rating']['field_instance']['display']['ding_item_viewer_big'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => '0',
    ); /* WAS: '' */
    $data['ting_object-ting_object-voxb_rating']['field_instance']['display']['ding_item_viewer_small'] = array(
      'label' => 'above',
      'settings' => array(),
      'type' => 'hidden',
      'weight' => 0,
    ); /* WAS: '' */
  }
}

/**
 * Implements hook_image_default_styles().
 */
function ding_item_viewer_image_default_styles() {
  $styles = array();

  // Exported image style: ding_item_viewer_image_big.
  $styles['ding_item_viewer_image_big'] = array(
    'name' => 'ding_item_viewer_image_big',
    'label' => 'Ding item viewer (big)',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '160',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: ding_item_viewer_image_small.
  $styles['ding_item_viewer_image_small'] = array(
    'name' => 'ding_item_viewer_image_small',
    'label' => 'Ding item viewer (small)',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '120',
          'height' => '',
          'upscale' => 1,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
