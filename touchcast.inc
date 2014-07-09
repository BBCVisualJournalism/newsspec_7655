<style>
#responsive-news .column--primary {
    width: 100%;
}
</style>
<div class="touchcast-holder"></div>
<script>

require(['jquery-1'], function ($) {

    function browserIsNotHtmlFiveCompatible () {
        return !!!document.createElement('video').canPlayType;
    }

    var id              = '42870',
        touchcastHolder = $('.touchcast-holder'),
        width           = touchcastHolder.width(),
        height          = (width / 16) * 9,
        src             = '//www.touchcast.com/embed/' + id;

    if (browserIsNotHtmlFiveCompatible()) {
        src += '&amp;mode=2';
    }
    touchcastHolder.append('<iframe width="' + width + '" height="' + height + '" src=" ' + src + '" frameborder="0" scrolling="no" allowfullscreen></iframe>');
});
</script>