<!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)&imageurl=((https?:\/\/)?([\da-z\.-]+)\.([a-z\.]{2,6})([\/\w \.-]*)*\/?)/" -->
    <!--#set var="TOUCHCAST_ID" value="$1" -->
    <!--#set var="IMAGE_URL" value="$2" -->
    <style>
    #responsive-news .column--primary {
        width: 100%;
    }
    .touchcast-cta {
        background: url(/news/special/2014/newsspec_7655/hand-icon.png) no-repeat;
        color: #007f7f;
        font-size: 1.5em;
        font-weight: bold;
        line-height: 48px;
        margin-bottom: 10px;
        padding-left: 58px;
        text-transform: uppercase;
    }
    .touchcast-cta__span {
        color: #050505;
        font-size: 0.75em;
        text-transform: initial;
    }
    .touchcast-holder {
        margin-bottom: 10px;
    }
    </style>
    <div class="touchcast-holder"></div>
    <script>
    var loadTouchcast = true;
    if (
        (document.documentMode && (document.documentMode < 10)) ||
        (/MSIE (7)/.test(navigator.userAgent))
    ) {
        loadTouchcast = false;
    }

    if (loadTouchcast) {
        require(['jquery-1'], function ($) {
            var id              = '<!--#echo var="TOUCHCAST_ID" -->',
                touchcastHolder = $('.touchcast-holder'),
                width           = touchcastHolder.width(),
                height          = (width / 16) * 9,
                src             = '//bbc-vip.touchcast.com/embed/' + id;

            $('.newsspec_7655__not-supported').hide();
            touchcastHolder.before('<div class="touchcast-cta">Interactive Video <span class="touchcast-cta__span">A new way of watching video – click or touch on the panels when they appear</span></div>');
            touchcastHolder.append('<iframe width="' + width + '" height="' + height + '" src=" ' + src + '" frameborder="0" scrolling="no" allowfullscreen></iframe>');
        });
    }
    alert('<!--#echo var="IMAGE_URL" -->');
    </script>
<!--#else -->
    <!-- TOUCHCAST ID OR IMAGE URL NOT FOUND -->
<!--#endif -->