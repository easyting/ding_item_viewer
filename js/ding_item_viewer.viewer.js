(function ($) {
  Drupal.behaviors.ding_item_viewer = {
    attach: function(context) {
      var ting_objects = eval(Drupal.settings.ding_item_viewer.ting_objects);
      var ting_indexes = new Array();
      var offset = 0;
      var object_offset = 0;
      var current_tab = 0;

      /**
       * Set active viewer tab.
       *
       * @param tab_index
       *   Integer, representing tab index.
       */
      var set_tab = function(tab_index) {
        current_tab = tab_index;
        get_object_indexes();
      }

      /**
       * Calculate ting objects count, returned by BE.
       */
      var get_objects_count = function() {
        var count = 0;
        for (key in ting_objects[current_tab]) {
          count++;
        }

        return count;
      }

      /**
       * A very simple emulation of php's array_keys().
       *
       * Since we are required to access JSON object within 0..x indeces,
       * and BE returned data keyed by ting id,
       * create an array of ting id's.
       */
      var get_object_indexes = function() {
        var i = 0;
        for (var key in ting_objects[current_tab]) {
          ting_indexes[i] = key;
          i++;
        }
      }

      /**
       * Fill the viewer with items.
       *
       * This considers current offset and active tab.
       */
      var populate_viewer = function() {
        $('.browsebar-inner').animate({opacity: 0}, 100, function() {
          $('.browsebar-inner .browsebar-item').each(function(i, e) {
            var item = $(this);

            // Loop through ting objects, so the script doesn't get stuck,
            // when it reached the end of the JSON object.
            var count = get_objects_count();
            if (object_offset >= count) {
              object_offset = 0;
            }

            // The center item requires some special treatment.
            if (i != 3) {
              item.find('.title').html(ting_objects[current_tab][ting_indexes[object_offset]].title);
              item.find('img.image').attr('src', ting_objects[current_tab][ting_indexes[object_offset]].image);
              item.find('.author').html(ting_objects[current_tab][ting_indexes[object_offset]].creator);
            }
            else {
              item.find('img.image').attr('src', ting_objects[current_tab][ting_indexes[object_offset]].image);
              item.find('.active-title').html(ting_objects[current_tab][ting_indexes[object_offset]].title);
              item.find('.active-author').html(ting_objects[current_tab][ting_indexes[object_offset]].creator);
              item.find('.active-description').html(ting_objects[current_tab][ting_indexes[object_offset]].description);
              item.find('.genre a').html(ting_objects[current_tab][ting_indexes[object_offset]].subject).attr('href', 'search/ting/' + ting_objects[current_tab][ting_indexes[object_offset]].subject);
              item.find('.active-rating').attr('class', 'active-rating rating-' + ting_objects[current_tab][ting_indexes[object_offset]].rating);
              item.find('.rating-count').html('(' + ting_objects[current_tab][ting_indexes[object_offset]].rating_count + ')');
              item.find('.review-count').html('(' + ting_objects[current_tab][ting_indexes[object_offset]].comment_count + ')');
              item.find('.active-more-info').attr('href', 'ting/object/' + ting_objects[current_tab][ting_indexes[object_offset]].id);
            }

            object_offset++;
          });
        });

        // Make some delay, to make sure that replacement takes in a invisible
        // way.
        setTimeout(function() {
          $('.browsebar-inner').animate({opacity: 1}, 100);
        }, 200);
      }

      // Process item clicks.
      $('.browsebar-inner .browsebar-item').click(function() {
        offset += $(this).index() - 3;
        var count = get_objects_count();

        // Clamp the offset to the 0..x limits,
        // where x is the ting objects count.
        if (offset <= 0) {
          offset = count - 1;
        }
        else if (offset >= count) {
          offset = 0;
        }

        object_offset = offset;
        // No need to munge the viewer if the active item was clicked.
        if ($(this).index() != 3) {
          populate_viewer();
        }
      });

      // By default, the first tab is active.
      $('.ui-tabs-nav li:first').addClass('active');

      // Process tab clicks.
      $('.ui-tabs-nav li').click(function() {
        $(this).parent().find('li').removeClass('active');
        $(this).addClass('active');
        set_tab($(this).index());
        offset = 0;
        object_offset = 0;

        populate_viewer();

        return false;
      });

      // Entry point.
      set_tab(0);
      populate_viewer();
    }
  }
})(jQuery);
