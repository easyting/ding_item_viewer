(function ($) {
  var container,// Ding Item Viewer container (main div).
    content, // Ding Item Viewer item container (div with items).
    settings,// Settings passed via Drupal.settings.
    tabs = [],// index => object_id mapping.
    items = [],// Items received from server.
    current_tab = 0,
    starting_item = 0,
    wait_time = 1000; // Time interval when to try to fetch data in ms.

  $(document).ready(function(){
    // Load data from server.
    container = $('.ding-item-viewer');
    $('a.tab', container).live('click', tab_change);
    fetch_data();
  });

  function fetch_data() {
    $.get(container.data('url'), container_callback);
  }

  /**
   * AJAX success callback function.
   *
   * @see jQuery.get()
   */
  function container_callback(response, textStatus, jqXHR) {
    if (response.status == 'BUSY') {
      setTimeout(fetch_data, wait_time);
      // Increase interval between retries. Reduce server load.
      wait_time *= 1.5;
    }
    else if (response.status == 'OK') {
      container.html(response.data.content);
      container.append(response.data.tabs);
      items = response.data.items;
      container.find('.ui-tabs-nav li:first').addClass('active');

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
    var tab, i, id, ids = [];
    // Build index => object_id mapping for quick access (DingItemViewer.tabs).
    for(tab = 0; tab < items.length; tab++) {
      tabs[tab] = [];
      i = 0;
      for(id in items[tab]) {
        tabs[tab][i] = id;
        i++;
        ids.push(id);
      }
    }
    // Get settings.
    settings = Drupal.settings.ding_item_viewer;

    // Get reservation buttons.
    if (typeof(DingAvailability.process) != 'undefined') {
      DingAvailability.process('availability', ids, function(){});
    }

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

    var visible = Math.min(settings.visible_items, tabs[current_tab].length);
    var big_item_positon = settings.big_item_positon;
    if (visible < settings.visible_items) {
      big_item_positon = Math.floor(visible / 2);
    }

    // Show specified number of items on screen.
    for (i = 0; i < visible; i++) {
      index = (i + starting_item) % tabs[current_tab].length;
      id = tabs[current_tab][index];

      // "Big" item.
      if (i == big_item_positon) {
        item = $(items[current_tab][id].big);
        item.addClass('active');

        // Show reservation button. Dirty hack.
        if (typeof(DingAvailability.availability_cache[id]) != 'undefined') {
          var reservation = item.find('.reservation-link-ajax');
          if (reservation) {
            if (DingAvailability.availability_cache[id].show_reservation_button) {
              reservation.removeClass('hidden');
            }
          }
        }
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

    // Preload images for current tab.
    for (i = 0; i < tabs[current_tab].length; i++) {
      id = tabs[current_tab][i];
      preload_images(items[current_tab][id]);
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
    var visible = Math.min(settings.visible_items, tabs[current_tab].length);
    var big_item_positon = settings.big_item_positon;
    if (visible < settings.visible_items) {
      big_item_positon = Math.floor(visible / 2);
    }

    rotation = position - big_item_positon;
    starting_item = starting_item + rotation;
    // For negative value start from the tail of list.
    if (starting_item < 0) {
      starting_item = tabs[current_tab].length + starting_item;
    }
    show_items();

    return false;
  }

  /**
   * Tab click event handler.
   *
   * Changes shown tab.
   */
  function tab_change(e) {
    e.preventDefault();

    starting_item = 0;
    current_tab = $(this).data('tab');
    container.find('.ui-tabs-nav li').removeClass('active');
    $(this).parent().addClass('active');

    show_items();
  }

  function preload_images(item) {
    var $item, src, img;
    $item = $(item.big);
    src = $item.find('img').attr('src');
    img = new Image();
    img.src = src;

    $item = $(item.small);
    src = $item.find('img').attr('src');
    img = new Image();
    img.src = src;
  }
})(jQuery);

