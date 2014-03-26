<?php
/**
 * @file
 * ding_item_viewer.features.features_overrides.inc
 */

/**
 * Implements hook_features_override_default_overrides().
 */
function ding_item_viewer_features_override_default_overrides() {
  // This code is only used for UI in features. Exported alters hooks do the magic.
  $overrides = array();

  // Exported overrides for: field
  $overrides["field.ting_object-ting_object-ding_availability_holdings.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '30',
  );
  $overrides["field.ting_object-ting_object-ding_availability_holdings.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );
  $overrides["field.ting_object-ting_object-ding_entity_buttons.field_instance|display|ding_item_viewer_big"] = array(
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
  );
  $overrides["field.ting_object-ting_object-ding_entity_buttons.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '23',
  );
  $overrides["field.ting_object-ting_object-ding_periodical_issues.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '27',
  );
  $overrides["field.ting_object-ting_object-ting_abstract.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'hidden',
    'module' => 'ding_item_viewer',
    'settings' => array(
      'trim_length' => '400',
    ),
    'type' => 'ting_abstract_ding_item_viewer',
    'weight' => '35',
  );
  $overrides["field.ting_object-ting_object-ting_abstract.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '34',
  );
  $overrides["field.ting_object-ting_object-ting_author.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'hidden',
    'module' => 'ding_item_viewer',
    'settings' => array(),
    'type' => 'ting_author_ding_item_viewer',
    'weight' => '34',
  );
  $overrides["field.ting_object-ting_object-ting_author.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'hidden',
    'module' => 'ding_item_viewer',
    'settings' => array(),
    'type' => 'ting_author_ding_item_viewer',
    'weight' => '2',
  );
  $overrides["field.ting_object-ting_object-ting_cover.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'hidden',
    'module' => 'ding_item_viewer',
    'settings' => array(
      'image_style' => 'ding_item_viewer_image_big',
    ),
    'type' => 'ting_cover_ding_item_viewer',
    'weight' => '1',
  );
  $overrides["field.ting_object-ting_object-ting_cover.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'hidden',
    'module' => 'ting_covers',
    'settings' => array(
      'image_style' => 'ding_item_viewer_image_small',
    ),
    'type' => 'ting_cover_default',
    'weight' => '0',
  );
  $overrides["field.ting_object-ting_object-ting_details_age.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '22',
  );
  $overrides["field.ting_object-ting_object-ting_details_age.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '21',
  );
  $overrides["field.ting_object-ting_object-ting_details_audience.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '0',
  );
  $overrides["field.ting_object-ting_object-ting_details_classification.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '35',
  );
  $overrides["field.ting_object-ting_object-ting_details_description.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '10',
  );
  $overrides["field.ting_object-ting_object-ting_details_extent.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '6',
  );
  $overrides["field.ting_object-ting_object-ting_details_format.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '43',
  );
  $overrides["field.ting_object-ting_object-ting_details_genre.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '41',
  );
  $overrides["field.ting_object-ting_object-ting_details_isbn.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '8',
  );
  $overrides["field.ting_object-ting_object-ting_details_isbn.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '7',
  );
  $overrides["field.ting_object-ting_object-ting_details_language.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '42',
  );
  $overrides["field.ting_object-ting_object-ting_details_subjects.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'inline',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '3',
  );
  $overrides["field.ting_object-ting_object-ting_subjects.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'inline',
    'module' => 'ding_item_viewer',
    'settings' => array(),
    'type' => 'ting_subjects_ding_item_viewer',
    'weight' => '36',
  );
  $overrides["field.ting_object-ting_object-ting_title.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'settings' => array(
      'link_type' => 'none',
    ),
    'type' => 'ting_title_default',
    'weight' => '0',
  );
  $overrides["field.ting_object-ting_object-ting_title.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'hidden',
    'module' => 'ting',
    'type' => 'ting_title_default',
    'weight' => '1',
  );
  $overrides["field.ting_object-ting_object-voxb_rating.field_instance|display|ding_item_viewer_big"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => '0',
  );
  $overrides["field.ting_object-ting_object-voxb_rating.field_instance|display|ding_item_viewer_small"] = array(
    'label' => 'above',
    'settings' => array(),
    'type' => 'hidden',
    'weight' => 0,
  );

 return $overrides;
}
