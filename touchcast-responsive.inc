<!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)&imageurl=((http.*\.)(jpe?g|png|[tg]iff?|svg))/" -->
    
    <!--#set var="TOUCHCAST_ID" value="$1" -->
    
    <!--#set var="IMAGE_URL" value="$2" -->

    <!--#if expr="$QUERY_STRING = /service=([a-zA-Z]+)/" -->
        <!--#set var="SERVICE" value="$1" -->
    <!--#else -->
        <!--#set var="SERVICE" value="en" -->
    <!--#endif -->

    <div id="touchcast-container" style="margin-top: 1em"></div>
    <script>
        require(['jquery-1'], function ($) {

            $('body').addClass('full-width-mode');

            var minWidth = 768;
            var serviceId = '<!--#echo var="SERVICE" -->';

            var textValues = [];
            textValues['en'] = {
                desc: 'You can find the non-interactive version of this content below.',
                noSupport: 'Your browser does not support this interactive video.'
            };
            var currentLangText = (serviceId in textValues) ? textValues[serviceId] : textValues['en'],
                touchcastContainer = document.getElementById('touchcast-container');

            function browserIsWorthyOfTouchcast () {
                return (
                    ($('body').width() >= minWidth) &&
                    (window.matchMedia) &&
                    (Function.prototype.bind) &&
                    !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
                ) ||
                (/IE /.test(navigator.userAgent) && /Trident\/[^34]/.test(navigator.userAgent) );
            }

            function displayNotSupportedMsg() {
                touchcastContainer.innerHTML = '<p><strong>' + currentLangText.noSupport + '</strong></p>';
            }

            function displayTouchcastHolder () {
                touchcastContainer.innerHTML = '<a href="http://bbc-vip.touchcast.com/bbc/<!--#echo var="TOUCHCAST_ID" -->?autoplay=1" class="touchcast-holder" target="_blank"><img src="<!--#echo var="IMAGE_URL" -->" /></a><p><strong>' + currentLangText.desc + '</strong></p>';
            }

            /*
                Temporary requirement until the domestic News site goes fully responsive.
            */
            function hideResponsiveNotSupportedInclude () { 
                $('.newsspec_7655__not-supported').hide();
            }

            function conditionallyDisplayTouchcast () {
                hideResponsiveNotSupportedInclude();
                if (browserIsWorthyOfTouchcast()){
                    displayTouchcastHolder();
                }
                else {
                    displayNotSupportedMsg();
                }
            }

            conditionallyDisplayTouchcast();

        });
    </script>
<!--#else -->
    <!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)/" -->
        <!-- IMAGE URL NOT FOUND -->
    <!--#else -->
        <!-- TOUCHCAST ID NOT FOUND -->
    <!--#endif -->
<!--#endif -->