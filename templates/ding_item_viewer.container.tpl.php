<?php
/**
 * @file
 * Template file for viewer container.
 *
 * Variables:
 *   $url - URL to AJAX handler.
 *   $preload_image - Image tag for "loading.." spinner.
 */
?>
<div class="ding-item-viewer" data-url="<?php echo $url; ?>">
  <div class="ding-item-viewer-preloader">
    <?php echo $preload_image; ?>
  </div>
</div>
