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

            function getTranslations () {
                return {
                    "en": {
                        "desc":      "You can find the non-interactive version of this content below.",
                        "noSupport": "Your browser does not support this interactive video."
                    },
                    "ar": {
                        "desc":      "الاطلاع على نسخة غير تفاعلية من ذات المحتوى أدناه.",
                        "noSupport": "متصفحك لا يدعم هذا الفيديو التفاعلي. يمكن"
                    },
                    "az": {
                        "desc":      "İnteraktiv olmayan versiyası aşağıdadır.",
                        "noSupport": "Brauzeriniz bu interaktiv video üçün uyğun deyil."
                    },
                    "bn": {
                        "desc":      "এই কন্টেন্টে-এর নন-ইন্টার‍্যাকটিভ ভার্সন পাওয়া যাবে নিচে।",
                        "noSupport": "এই ইন্টার‍্যাকটিভ ভিডিওটি আপনার ব্রাউজারে দেখা যাবে না।"
                    },
                    "pr-BR": {
                        "desc":      "Abaixo, você pode checar a versão não interativa deste item.",
                        "noSupport": "Este vídeo interativo não funciona com o navegador que você está utilizando."
                    },
                    "zh-Hans--simp": {
                        "desc":      "你可以在下方找到本内容的非互动版。",
                        "noSupport": "你使用的浏览器不支持这一互动视频。"
                    },
                    "zh-Hans--trad": {
                        "desc":      "你可以在下方找到本内容的非互動版。",
                        "noSupport": "你使用的瀏覽器不支持這一互動視頻。"
                    },
                    "cy-GB": {
                        "desc":      "Gallwch ddod o hyd i fersiwn sydd ddim yn ryngweithiol isod.",
                        "noSupport": "Dyw'r porwr ddim yn cefnogi'r fideo rhyngweithiol yma."
                    },
                    "ha": {
                        "desc":      "Za ka iya samun salon da ba na latsawa ba a nan kasa.",
                        "noSupport": "Manhajarka ba ta iya daukar wannan bidiyon da ake latsawa."
                    },
                    "ky": {
                        "desc":      "Интерактивдүү эмес версияны төмөн жактан таба аласыз.",
                        "noSupport": "Сиздин браузериңиз бул интерактивдүү видеону ачпайт."
                    },
                    "es": {
                        "desc":      "Más abajo puede encontrar la versión no interactiva de este contenido.",
                        "noSupport": "Su navegador web no permite reproducir este video interactivo."
                    },
                    "fa": {
                        "desc":      "می توانید نسخه غیرقابل کلیک این محتوا را در پایین ببینید.",
                        "noSupport": "این ویدیوی قابل کلیک با مرورگر شما قابل پخش نیست."
                    },
                    "ru": {
                        "desc":      "С неинтерактивной версией можно ознакомиться ниже.",
                        "noSupport": "Ваш браузер не поддерживает это интерактивное видео."
                    },
                    "so": {
                        "desc":      "Waxaad hoos ka heli kartaa qayb caadi ah",
                        "noSupport": "Browser-kaaga ma taageerayo ka qaybgalka video-ga."
                    },
                    "uk": {
                        "desc":      "З неінтерактивною версією можна ознайомитися нижче.",
                        "noSupport": "Ваш браузер не підтримує це інтерактивне відео."
                    },
                    "ur": {
                        "desc":      "آپ اس مواد کو غیر انٹرایکٹو شکل میں نیچے دیکھ سکتے ہیں۔",
                        "noSupport": "آپ کا براؤزر یہ ویڈیو نہیں چلا سکتا۔"
                    },
                    "uz": {
                        "desc":      "Қуйида ушбу мазмуннинг интерактив бўлмаган вариантини ҳам топишингиз мумкин",
                        "noSupport": "Сизнинг браузерингиз бу интерактив видеони ишлатолмайди."
                    },
                    "vi": {
                        "desc":      "Mời bạn xem phiên bản không tương tác dưới đây.",
                        "noSupport": "Trình duyệt của bạn không hỗ trợ xem video tương tác này."
                    }
                };
            }

            $('body').addClass('full-width-mode');

            var minWidth = 768;
            var serviceId = '<!--#echo var="SERVICE" -->';

            var textValues = getTranslations()
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
                touchcastContainer.innerHTML = '<a href="http://bbc-vip.touchcast.com/embed/<!--#echo var="TOUCHCAST_ID" -->?autoplay=1" class="touchcast-holder" target="_blank"><img src="<!--#echo var="IMAGE_URL" -->" /></a><p><strong>' + currentLangText.desc + '</strong></p>';
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