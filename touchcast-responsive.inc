<!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)&imageurl=((http.*\.)(jpe?g|png|[tg]iff?|svg))/" -->
<!--#set var="TOUCHCAST_ID" value="$1" -->
<!--#set var="IMAGE_URL" value="$2" -->

<div id="touchcast-container"></div>
<script>
    /*! viewportSize | Author: Tyson Matanich, 2013 | License: MIT */
    (function(n){n.viewportSize={},n.viewportSize.getHeight=function(){return t("Height")},n.viewportSize.getWidth=function(){return t("Width")};var t=function(t){var f,o=t.toLowerCase(),e=n.document,i=e.documentElement,r,u;return n["inner"+t]===undefined?f=i["client"+t]:n["inner"+t]!=i["client"+t]?(r=e.createElement("body"),r.id="vpw-test-b",r.style.cssText="overflow:scroll",u=e.createElement("div"),u.id="vpw-test-d",u.style.cssText="position:absolute;top:-1000px",u.innerHTML="<style>@media("+o+":"+i["client"+t]+"px){body#vpw-test-b div#vpw-test-d{"+o+":7px!important}}<\/style>",r.appendChild(u),i.insertBefore(r,e.head),f=u["offset"+t]==7?i["client"+t]:n["inner"+t],i.removeChild(r)):f=n["inner"+t],f}})(this);

    var minWidth = 976;

    function getViewPort (){
        return {
            width: viewportSize.getWidth(),
            height: viewportSize.getHeight()
        }
    }

    function browserIsWorthyOfTouchcast () {
        return (
            (getViewPort().width >= minWidth) &&
            (window.matchMedia) &&
            (Function.prototype.bind) &&
            !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
        ) ||
        (/IE 9/.test(navigator.userAgent));
    }

    function wouldBeWorthyIfRotated () {
        return (
            (getViewPort().height >= minWidth) &&
            (typeof window.orientation !== 'undefined')&&
            (window.matchMedia) &&
            (Function.prototype.bind) &&
            !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
        ) ||
        (/IE 9/.test(navigator.userAgent));
    }

    /* Tell the user to rotate their screen */
    function displayRotateText() {
        if(!document.querySelector('touchcast-rotate')) {
            document.getElementById('touchcast-container').innerHTML = '<span class="touchcast-rotate"><p><strong>Rotate your device to view the touchcast video</strong></p></span>';
        }
    }

    function displayToSmallText() {
        if(!document.querySelector('touchcast-increase')) {
            document.getElementById('touchcast-container').innerHTML = '<p class="touchcast-increase"><strong>Your browser width is too small to view the touchcast video. Please increase the browser width or use a different device.</strong></p>';
        }
    }

    function displayTouchcastHolder () {
        if(!document.querySelector('touchcast-holder')) {
            document.getElementById('touchcast-container').innerHTML = '<a href="http://bbc-vip.touchcast.com/bbc/<!--#echo var="TOUCHCAST_ID" -->&autoplay=1" class="touchcast-holder" target="_blank"><img src="<!--#echo var="IMAGE_URL" -->" /></a><p><strong>When you have finished watching, return to this page to vote. You can find the non-interactive version of this content below.</strong></p>';
        }
    }

    function conditionallyDisplayTouchcast () {
        if (browserIsWorthyOfTouchcast()){
            displayTouchcastHolder();
        }else if(wouldBeWorthyIfRotated()){
            displayRotateText();
        }else{
            displayToSmallText()
        }
    }

    conditionallyDisplayTouchcast();
    window.addEventListener('orientationchange', conditionallyDisplayTouchcast);

    /* Delayed resize, stops the browser from firing the conditionallyDisplayTouchcast() constantly while resizing */
    var timer;
    window.addEventListener("resize", function(){
        if(timer) { window.clearTimeout(timer); }
        timer = window.setTimeout(function() {
            conditionallyDisplayTouchcast();
        }, 50);
    });

</script>
<!--#else -->
    <!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)/" -->
        <!-- IMAGE URL NOT FOUND -->
    <!--#else -->
        <!-- TOUCHCAST ID NOT FOUND -->
    <!--#endif -->
<!--#endif -->