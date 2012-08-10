(function ($) {
  Drupal.behaviors.ding_item_viewer = {
    attach: function(context) {
      var ting_objects = eval(Drupal.settings.ding_item_viewer.ting_objects);
      var ting_indexes = new Array();
      var offset = 0;
      var object_offset = 0;
      var current_tab = 0;

      var set_tab = function(tab_index) {
        current_tab = tab_index;
        get_object_indexes();
      }

      var get_objects_count = function() {
        var count = 0;
        for (key in ting_objects[current_tab]) {
          count++;
        }

        return count;
      }

      var get_object_indexes = function() {
        var i = 0;
        for (var key in ting_objects[current_tab]) {
          ting_indexes[i] = key;
          i++;
        }
      }

      var populate_viewer = function() {
        $('.browsebar-inner').animate({opacity: 0}, 100, function() {
          $('.browsebar-inner .browsebar-item').each(function(i, e) {
            var item = $(this);

            var count = get_objects_count();
            if (object_offset >= count) {
              object_offset = 0;
            }

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

        setTimeout(function() {
          $('.browsebar-inner').animate({opacity: 1}, 100);
        }, 200);
      }

      $('.browsebar-inner .browsebar-item').click(function() {
        offset += $(this).index() - 3;
        var count = get_objects_count();

        if (offset <= 0) {
          offset = count - 1;
        }
        else if (offset >= count) {
          offset = 0;
        }

        object_offset = offset;
        if ($(this).index() != 3) {
          populate_viewer();
        }
      });

      $('.ui-tabs-nav li:first').addClass('active');

      $('.ui-tabs-nav li').click(function() {
        $(this).parent().find('li').removeClass('active');
        $(this).addClass('active');
        set_tab($(this).index());
        offset = 0;
        object_offset = 0;

        populate_viewer();

        return false;
      });

      set_tab(0);
      populate_viewer();
    }
  }
})(jQuery);
