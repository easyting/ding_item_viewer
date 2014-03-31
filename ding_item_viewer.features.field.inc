<?php
/**
 * @file
 * ding_item_viewer.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function ding_item_viewer_field_default_fields() {
  $fields = array();

  // Exported field: 'ting_object-ting_object-more_info'.
  $fields['ting_object-ting_object-more_info'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'default_widget' => 'hidden',
      'deleted' => '0',
      'entity_types' => array(
        0 => 'ting_object',
      ),
      'field_name' => 'more_info',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => '0',
      'module' => 'ding_item_viewer',
      'no_ui' => TRUE,
      'settings' => array(),
      'storage' => array(
        'active' => '1',
        'module' => 'virtual_field',
        'settings' => array(),
        'type' => 'virtual_field',
      ),
      'translatable' => '0',
      'type' => 'ting_object_more_info',
    ),
    'field_instance' => array(
      'bundle' => 'ting_object',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'collection_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'collection_primary' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'ding_item_viewer',
          'settings' => array(),
          'type' => 'ting_object_more_info_default',
          'weight' => 42,
        ),
        'ding_item_viewer_big' => array(
          'label' => 'hidden',
          'module' => 'ding_item_viewer',
          'settings' => array(),
          'type' => 'ting_object_more_info_default',
          'weight' => '37',
        ),
        'ding_item_viewer_small' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'item_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'short_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'ting_object_fields' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'user_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'ting_object',
      'field_name' => 'more_info',
      'formatter' => array(
        'type' => 'ting_object_more_info_default',
      ),
      'label' => 'More info',
      'required' => FALSE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'virtual_field',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 41,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('More info');

  return $fields;
}
