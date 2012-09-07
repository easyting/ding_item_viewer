<?php
/**
 * @file
 * Template file for viewer layout.
 */
?>
<div class="browsebar-inner">
  <div class="browsebar-items-wrapper">
    <div class="browsebar-item even first">
      <div class="image-rating-wrapper">
        <img src="" class="image"alt="" />
        <div class="rating rating-0"></div>
      </div>
      <span class="title"></span>
      <span class="author"></span>
      <span class="more-info"><?php print t('More info'); ?></span>
    </div>
    <div class="browsebar-item odd">
      <div class="image-rating-wrapper">
        <img src="" class="image" alt="" />
        <div class="rating rating-0"></div>
      </div>
      <span class="title"></span>
      <span class="author"></span>
      <span class="more-info"><?php print t('More info'); ?></span>
    </div>
    <div class="browsebar-item even">
      <div class="image-rating-wrapper">
        <img src="" class="image" alt="" />
        <div class="rating rating-0"></div>
      </div>
      <span class="title"></span>
      <span class="author"></span>
      <span class="more-info"><?php print t('More info'); ?></span>
    </div>
    <div class="browsebar-item active">
      <div class="cover-wrapper">
        <img src="" class="image" alt="" />
        <div class="reserve-container">
          <span class="reserve-label"><?php print t('Reserve here'); ?></span>
          <div class="item-loan">
            
          </div>
        </div>
      </div>
      <div class="properties-wrapper">
        <h2 class="active-title"></h2>
        <span class="active-author"></span>
        <span class="active-description"></span>
        <span class="genre"><?php print t('Genre'); ?>: <a href="#"></a></span>
        <div class="active-rating rating-0"></div><span class="rating-count">(0)</span>
        <a href="#" class="reviews"><?php print t('Reviews'); ?> <span class="review-count">(0)</span></a>
        <a href="#" class="active-more-info"><?php print t('More info'); ?></a>
      </div>
    </div>
    <div class="browsebar-item even">
      <div class="image-rating-wrapper">
        <img src="" class="image" alt="" />
        <div class="rating rating-0"></div>
      </div>
      <span class="title"></span>
      <span class="author"></span>
      <span class="more-info"><?php print t('More info'); ?></span>
    </div>
    <div class="browsebar-item odd last">

    <div class="image-rating-wrapper">
      <img src="" class="image" alt="" />
      <div class="rating rating-0"></div>
    </div>
    <span class="title"></span>
    <span class="author"></span>
    <span class="more-info"><?php print t('More info'); ?></span>
  </div>
  </div>
</div>
<?php print $tabs; ?>
