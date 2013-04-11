<?php
/**
 * @file
 *
 * Template for ding item viewer item.
 *
 * Variables:
 *   $item - Object containing item info.
 */
?>
<div class="browsebar-item active">
  <div class="active-item-title">
    <h2>
      <a href="<?php echo url('ting/object/' . $item->id); ?>" class="active-title active-more-info"><?php echo $item->title; ?></a>
    </h2>
  </div>
  <div class="cover-wrapper">
    <div class="cover-wrapper-inner">
      <img src="<?php echo $item->image; ?>" class="image"
        alt="<?php echo $item->title . ' ' . $item->year; ?>" />
    </div>
    <div class="reserve-container">
      <div class="item-loan">
        <?php print l(
          t('Reserve'),
          'reservation/reserve/' . $item->localId,
          array('attributes' => array('id' => 'reserve-' . $item->localId))
          );
        ?>
      </div>
    </div>
  </div>
  <div class="properties-wrapper">
    <span class="active-author"><?php echo $item->creator; ?></span>
    <span class="active-description"><?php echo $item->description; ?></span>
    <span class="genre"><?php print t('Genre'); ?>:
      <a href="<?php echo url('search/ting/' . $item->subject); ?>"><?php echo $item->subject; ?></a>
    </span>
    <div class="active-rating rating-<?php echo $item->rating; ?>"></div>
    <span class="rating-count">(<?php echo $item->rating_count;?>)</span>
    <a href="#" class="reviews"><?php print t('Reviews'); ?><span class="review-count">(<?php echo $item->comment_count; ?>)</span></a>
    <a href="<?php echo url('ting/object/' . $item->id); ?>" class="active-more-info"><?php print t('More info'); ?></a>
  </div>
</div>
