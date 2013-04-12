<?php
/**
 * @file
 *
 * Template for ding item viewer item.
 *
 * Variables:
 *   $item - Object containing item info.
 *   $item_class - Additional classes for item wrapper.
 */
?>
<div class="browsebar-item <?php echo $item_class; ?>">
  <div class="image-rating-wrapper">
    <img src="<?php echo $item->image; ?>" class="image"
      alt="<?php echo $item->title . ' ' . $item->year; ?>" />
    <div class="rating rating-0"></div>
  </div>
  <span class="title"><?php echo $item->title; ?></span>
  <span class="author"><?php echo $item->creator; ?></span>
  <span class="more-info"><?php print t('More info'); ?></span>
</div>
