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
        document.write('<' + 'a href="//bbc-vip.touchcast.com/embed/--TOUCHCAST_ID--" class="touchcast-holder" target="_blank"><img src="/touchcast_aquatic.jpg" /></a' + '>');
    }
</script>