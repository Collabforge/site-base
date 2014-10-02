jQuery(document).ready(function($) {
    $('#tab-container').easytabs({
      collapsedByDefault: true
      , collapsible: true
    }).bind('easytabs:after', function() {
      $('html, body').animate({
        scrollTop: $(this).offset().top
      }, 0);      
    });
    $('.ui-tab-content').height($(window).height());
    $('.ui-mobile-menu .etabs').height('50');
    //alert('salam');
});
