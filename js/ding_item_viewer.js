(function ($) {
  Drupal.behaviors.ding_item_viewer = {
    attach: function(context) {
      $('.browsebar-inner', context).once(function() {
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
         * Attach AJAX handler to a reservation link.
         */
        var attach_ajax = function(reserve_link) {
          var element_settings = {};
          element_settings.url = reserve_link.attr('href');
          element_settings.event = 'click';
          element_settings.progress = {
            type: 'throbber',
            message: ''
          };
          var base = reserve_link.attr('id');
          Drupal.ajax[base] = new Drupal.ajax(base, reserve_link, element_settings);

          reserve_link.unbind(Drupal.ajax[base].event);
          reserve_link.bind(Drupal.ajax[base].event, function (event) {
            return Drupal.ajax[base].eventResponse(reserve_link, event);
          });
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

              if (count == 0) {
                $('#block-ding-item-viewer-item-viewer').html('').hide();
                return;
              }

              // The center item requires some special treatment.
              var ting_object = ting_objects[current_tab][ting_indexes[object_offset]];
              if (i != 3) {
                item.find('.title').html(ting_object.title);
                item.find('img.image').attr('src', ting_object.image);
                item.find('.author').html(ting_object.creator);
              }
              else {
                item.find('img.image').attr('src', ting_object.image);
                item.find('.active-title').html(ting_object.title);
                item.find('.active-author').html(ting_object.creator);
                item.find('.active-description').html(ting_object.description);
                item.find('.genre a').html(ting_object.subject).attr('href', 'search/ting/' + ting_object.subject);

                // Show ratings/reviews for items with ISBN.
                if (ting_object.has_rating) {
                  item.find('.active-rating').attr('class', 'active-rating rating-' + ting_object.rating).show();
                  item.find('.rating-count').html('(' + ting_object.rating_count + ')').show();
                  item.find('.reviews').show();
                  item.find('.review-count').html('(' + ting_object.comment_count + ')');
                }
                else {
                  item.find('.active-rating').hide();
                  item.find('.rating-count').hide();
                  item.find('.reviews').hide();
                }

                item.find('.active-more-info').attr('href', 'ting/object/' + ting_object.id);
                var reserve_link = item.find('.reserve-container a');
                reserve_link.attr('href', 'reservation/reserve/' + ting_object.localId);
                reserve_link.attr('id', 'reserve-' + ting_object.localId);
                attach_ajax(reserve_link);
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
      });
    }
  }
})(jQuery);
