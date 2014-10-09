<script>
    function browserIsWorthyOfTouchcast () {
        return (
            (document.body.clientWidth >= 305) &&
            (window.matchMedia) &&
            (Function.prototype.bind) &&
            !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
        ) ||
        (/IE9/.test(navigator.userAgent));
    }
    if (browserIsWorthyOfTouchcast() && window.innerWidth > 1024){
        document.write('<' + 'a href="//bbc-vip.touchcast.com/embed/--TOUCHCAST_ID--" class="touchcast-holder" target="_blank"><' + 'img src="http://news.bbcimg.co.uk/news/special/2014/newsspec_7655/img/touchcast_lse.jpg" /' + '></a' + '>');
    }
</script>
<p><strong>When you have finished watching, return to this page to vote.</strong></p>
