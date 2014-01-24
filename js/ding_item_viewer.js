(function ($) {
  var container,// Ding Item Viewer container (main div).
    content, // Ding Item Viewer item container (div with items).
    settings,// Settings passed via Drupal.settings.
    tabs = [],// index => object_id mapping.
    items = [],// Items received from server.
    current_tab = 0,
    starting_item = 0;

  $(document).ready(function(){
    // Load data from server.
    container = $('.ding-item-viewer');
    $.get(container.data('url'), container_callback);
  });

  /**
   * AJAX success callback function.
   *
   * @see jQuery.get()
   */
  function container_callback(response, textStatus, jqXHR) {
    if (response.status == 'OK') {
      container.html(response.data.content);
      container.append(response.data.tabs);
      items = response.data.items;
      prepare_data();
      show_items();
    }
    else {
      container.html(response.error);
    }
  }

  /**
   * Prepare data before viewing it.
   */
  function prepare_data() {
    var tab, i, id;
    // Build index => object_id mapping for quick access (DingItemViewer.tabs).
    for(tab = 0; tab < items.length; tab++) {
      tabs[tab] = [];
      i = 0;
      for(id in items[tab]) {
        tabs[tab][i] = id;
        i++;
      }
    }
    // Get settings.
    settings = Drupal.settings.ding_item_viewer;

    // Get item container.
    content = container.find('.browsebar-items-wrapper');
  }

  /**
   * Show initial items.
   */
  function show_items() {
    var i, item, id, index;

    // Reset content.
    content.html('');

    // Show specified number of items on screen.
    for (i = 0; i < settings.visible_items; i++) {
      index = (i + starting_item) % tabs[current_tab].length;
      id = tabs[current_tab][index];

      // "Big" item.
      if (i == settings.big_item_positon) {
        item = $(items[current_tab][id].big);
        item.addClass('active');
      }
      // "Small" items.
      else {
        item = $(items[current_tab][id].small);
        // Add even/odd class for proper positioning.
        if (i % 2 == 0) {
          item.addClass('even');
        }
        else {
          item.addClass('odd');
        }
        // Position on screen (helper info).
        item.data('position', i);

        // Attach onclick handler.
        item.click(item_click);
      }
      // Index in DingItemViewer.tabs (helper info).
      item.data('index', index);
      // Show item.
      item.addClass('browsebar-item');
      content.append(item);
    }
    // Add first/last classes.
    content.find(':first').addClass('first');
    content.find(':last').addClass('last');
  }

  /**
   * Small item onclick event handler.
   *
   * Moves clicked item in "big" view and shifts all other items in "circle".
   */
  function item_click() {
    var item = $(this),
      position = item.data('position'),
      index = item.data('index'),
      rotation; // Shift and direction of rotation.

    // Recalculate starting_item index and redraw content.
    rotation = position - settings.big_item_positon;
    starting_item = starting_item + rotation;
    // For negative value start from the tail of list.
    if (starting_item < 0) {
      starting_item = tabs[current_tab].length + starting_item;
    }
    show_items();

    return false;
  }

})(jQuery);

