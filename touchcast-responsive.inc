<!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)&imageurl=((http.*\.)(jpe?g|png|[tg]iff?|svg))/" -->
<!--#set var="TOUCHCAST_ID" value="$1" -->
<!--#set var="IMAGE_URL" value="$2" -->

<!--#if expr="$QUERY_STRING = /service=([a-zA-Z]+)/" -->
    <!--#set var="SERVICE" value="$1" -->
<!--#else -->
    <!--#set var="SERVICE" value="en" -->
<!--#endif -->

<div id="touchcast-container"></div>
<script>
    /*! viewportSize | Author: Tyson Matanich, 2013 | License: MIT */
    (function(n){n.viewportSize={},n.viewportSize.getHeight=function(){return t("Height")},n.viewportSize.getWidth=function(){return t("Width")};var t=function(t){var f,o=t.toLowerCase(),e=n.document,i=e.documentElement,r,u;return n["inner"+t]===undefined?f=i["client"+t]:n["inner"+t]!=i["client"+t]?(r=e.createElement("body"),r.id="vpw-test-b",r.style.cssText="overflow:scroll",u=e.createElement("div"),u.id="vpw-test-d",u.style.cssText="position:absolute;top:-1000px",u.innerHTML="<style>@media("+o+":"+i["client"+t]+"px){body#vpw-test-b div#vpw-test-d{"+o+":7px!important}}<\/style>",r.appendChild(u),i.insertBefore(r,e.head),f=u["offset"+t]==7?i["client"+t]:n["inner"+t],i.removeChild(r)):f=n["inner"+t],f}})(this);

    var minWidth = 976;
    var serviceId = '<!--#echo var="SERVICE" -->';

    var textValues = [];
    textValues['en'] = {
        desc: 'You can find the non-interactive version of this content below.',
        noSupport: 'Your browser does not support this interactive video.'
    };
    var currentLangText = (serviceId in textValues) ? textValues[serviceId] : textValues['en'];

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

    /* Tell the user to rotate their screen */
    function displayToSmallText() {
        document.getElementById('touchcast-container').innerHTML = '<p><strong>' + currentLangText.noSupport + '</strong></p>';
    }

    function displayTouchcastHolder () {
        document.getElementById('touchcast-container').innerHTML = '<a href="http://bbc-vip.touchcast.com/bbc/<!--#echo var="TOUCHCAST_ID" -->?autoplay=1" class="touchcast-holder" target="_blank"><img src="<!--#echo var="IMAGE_URL" -->" /></a><p><strong>' + currentLangText.desc + '</strong></p>';
    }

    function conditionallyDisplayTouchcast () {
        if (browserIsWorthyOfTouchcast()){
            displayTouchcastHolder();
        }else{
            displayToSmallText();
        }
    }

    conditionallyDisplayTouchcast();


</script>
<!--#else -->
    <!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)/" -->
        <!-- IMAGE URL NOT FOUND -->
    <!--#else -->
        <!-- TOUCHCAST ID NOT FOUND -->
    <!--#endif -->
<!--#endif -->