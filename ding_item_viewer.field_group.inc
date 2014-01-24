<?php
/**
 * @file
 * ding_item_viewer.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function ding_item_viewer_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_data|ting_object|ting_object|ding_item_viewer_big';
  $field_group->group_name = 'group_data';
  $field_group->entity_type = 'ting_object';
  $field_group->bundle = 'ting_object';
  $field_group->mode = 'ding_item_viewer_big';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Data',
    'weight' => '2',
    'children' => array(
      0 => 'ting_abstract',
      1 => 'ting_author',
      2 => 'ting_subjects',
      3 => 'ding_entity_buttons',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Data',
      'instance_settings' => array(
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_data|ting_object|ting_object|ding_item_viewer_big'] = $field_group;

  return $export;
}
