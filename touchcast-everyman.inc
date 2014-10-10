<script>
    function browserIsWorthyOfTouchcast () {
        return (
            (document.body.clientWidth >= 305) &&
            (window.matchMedia) &&
            (Function.prototype.bind) &&
            !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
        ) ||
        (/IE 9/.test(navigator.userAgent));
    }
    if (browserIsWorthyOfTouchcast() && window.innerWidth > 1024){
        document.write('<' + 'a href="http://bbc-vip.touchcast.com/bbc/19571&autoplay=1" class="touchcast-holder" target="_blank"><' + 'img src="http://news.bbcimg.co.uk/news/special/2014/newsspec_7655/img/touchcast_everyman.jpg" /' + '></a' + '>' + '<' + 'p><' + 'strong>When you have finished watching, return to this page to vote. You can find the non-interactive version of this content below.<' + '/strong' + '></p' + '>');
    }
</script>
