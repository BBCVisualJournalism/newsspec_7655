<!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)/" -->

    <!--#set var="TOUCHCAST_ID" value="$1" -->

    <!--#if expr="$QUERY_STRING = /imageurl=((http.*\.)(jpe?g|png|[tg]iff?|svg))/" -->
        <!--#set var="IMAGE_URL" value="$1" -->
    <!--#else -->
        <!--#set var="IMAGE_URL" value="" -->
    <!--#endif -->

    <!--#if expr="$QUERY_STRING = /service=([a-zA-Z]+)/" -->
        <!--#set var="SERVICE" value="$1" -->
    <!--#else -->
        <!--#set var="SERVICE" value="en" -->
    <!--#endif -->


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
    </style>

    <div id="touchcast-container" style="margin-top: 1em"></div>
    <script>
        require(['jquery-1'], function ($) {
            function getTranslations () {
                return {
                    "en": {
                        "desc":      "You can find the non-interactive version of this content below.",
                        "noSupport": "Your browser does not support this interactive video."
                    },

                    // Arabic
                    "ar": {
                        "desc":      "الاطلاع على نسخة غير تفاعلية من ذات المحتوى أدناه.",
                        "noSupport": "متصفحك لا يدعم هذا الفيديو التفاعلي. يمكن"
                    },

                    // Azeri
                    "az": {
                        "desc":      "İnteraktiv olmayan versiyası aşağıdadır.",
                        "noSupport": "Brauzeriniz bu interaktiv video üçün uyğun deyil."
                    },

                    // Bengali
                    "bn": {
                        "desc":      "এই কন্টেন্টে-এর নন-ইন্টার‍্যাকটিভ ভার্সন পাওয়া যাবে নিচে।",
                        "noSupport": "এই ইন্টার‍্যাকটিভ ভিডিওটি আপনার ব্রাউজারে দেখা যাবে না।"
                    },

                    // Brasil
                    "pr-BR": {
                        "desc":      "Abaixo, você pode checar a versão não interativa deste item.",
                        "noSupport": "Este vídeo interativo não funciona com o navegador que você está utilizando."
                    },

                    // Burmese
                    "my": {
                        "desc":      "အောက်မှာ non-interactive ဗားရှင်းကို  ကြည့်နိုင်ပါတယ်။",
                        "noSupport": "သင့်ရဲ့ ဘရောက်ဇာက interactive ဗီဒီယိုကို ဖွင့်လို့ မရပါ။"
                    },

                    // Chinese (Simple)
                    "zh-Hans": {
                        "desc":      "你可以在下方找到本内容的非互动版。",
                        "noSupport": "你使用的浏览器不支持这一互动视频。"
                    },

                    // Chinese (Traditional)
                    "zh-Hant": {
                        "desc":      "你可以在下方找到本内容的非互動版。",
                        "noSupport": "你使用的瀏覽器不支持這一互動視頻。"
                    },

                    // Cymru
                    "cy-GB": {
                        "desc":      "Gallwch ddod o hyd i fersiwn sydd ddim yn ryngweithiol isod.",
                        "noSupport": "Dyw'r porwr ddim yn cefnogi'r fideo rhyngweithiol yma."
                    },

                    // French
                    "fr": {
                        "desc":      "Une version non-interactive est disponible ci-bas.",
                        "noSupport": "Votre navigateur ne vous permet pas de voir cette vidéo interactive."
                    },

                    // Gahuza
                    "ha": {
                        "desc":      "Za ka iya samun salon da ba na latsawa ba a nan kasa.",
                        "noSupport": "Manhajarka ba ta iya daukar wannan bidiyon da ake latsawa."
                    },

                    // Hausa
                    "ky": {
                        "desc":      "Интерактивдүү эмес версияны төмөн жактан таба аласыз.",
                        "noSupport": "Сиздин браузериңиз бул интерактивдүү видеону ачпайт."
                    },

                    // Hindi
                    "hi": {
                        "desc":      "आप इस सामग्री का नॉन इंटरैक्टिव वर्जन नीचे पा सकते हैं",
                        "noSupport": "आपका ब्राउज़र इस इंटरैक्टिव वीडियो को सपोर्ट नहीं करता है"
                    },

                    // Indonesian
                    "id": {
                        "desc":      "Anda bisa menemukan versi noninteraktif dari materi ini di bawah",
                        "noSupport": "Mesin penjelajah Anda tidak mendukung video interaktif ini"
                    },

                    // Kyrgyz
                    "ky": {
                        "desc":      "Интерактивдүү эмес версияны төмөн жактан таба аласыз.",
                        "noSupport": "Сиздин браузериңиз бул интерактивдүү видеону ачпайт."
                    },

                    // Mundo
                    "es": {
                        "desc":      "Más abajo puede encontrar la versión no interactiva de este contenido.",
                        "noSupport": "Su navegador web no permite reproducir este video interactivo."
                    },

                    // Nepali
                    "ne": {
                        "desc":      "तपाईंंले इन्टरयाक्टिभ नभएको संस्करण तल हेर्न सक्नुहुनेछ।",
                        "noSupport": "तपाईंको  ब्राउजरले यो इन्टरयाक्टिभ  भिडियो सपोर्ट गर्दैन। "
                    },

                    // Pashto
                    "ps": {
                        "desc":      "تاسو د دې مطلب بې انځوره بڼه لاندې موندلى شئ",
                        "noSupport": "ستاسو براوزر د دې ويديو خپرولو ته جوړ نه دى"
                    },

                    // Persian
                    "fa": {
                        "desc":      "می توانید نسخه غیرقابل کلیک این محتوا را در پایین ببینید.",
                        "noSupport": "این ویدیوی قابل کلیک با مرورگر شما قابل پخش نیست."
                    },

                    // Russian
                    "ru": {
                        "desc":      "С неинтерактивной версией можно ознакомиться ниже.",
                        "noSupport": "Ваш браузер не поддерживает это интерактивное видео."
                    },

                    // Sinhala
                    "si": {
                        "desc":      "ඔබ පහත මෙම අන්තර්ගතය නොවන අන්තර් ක්රියාකාරී අනුවාදය සොයා ගත හැකි වනු ඇත.",
                        "noSupport": "ඔබේ වෙබ් ගවේශකය මෙම අන්තර් කි්රයාකාරී වීඩියෝ සඳහා පහසුකම් සපයන්නේ නැත."
                    },

                    // Somali
                    "so": {
                        "desc":      "Waxaad hoos ka heli kartaa qayb caadi ah",
                        "noSupport": "Browser-kaaga ma taageerayo ka qaybgalka video-ga."
                    },

                    // Swahili
                    "sw": {
                        "desc":      "Unaweza kupata mbadala hapo chini",
                        "noSupport": "Kirambaza chako hakiwezi kucheza video hii"
                    },

                    // Tamil
                    "ta": {
                        "desc":      "நீ்ங்கள் பங்கேற்காத வகையிலான இதே செய்தியின் இணைப்பு கீழே",
                        "noSupport": "நீங்களும் பங்கேற்கும் வகையிலான இந்த காணொளியை இந்த உலாவியில் காணமுடியாது."
                    },

                    // Turkish
                    "tr": {
                        "desc":      "İçeriğin interaktif olmayan halini aşağıda bulabilirsiniz.",
                        "noSupport": "Tarayıcınız bu interaktif videoyu açamıyor."
                    },

                    // Ukrainian
                    "uk": {
                        "desc":      "З неінтерактивною версією можна ознайомитися нижче.",
                        "noSupport": "Ваш браузер не підтримує це інтерактивне відео."
                    },

                    // Urdu
                    "ur": {
                        "desc":      "آپ اس مواد کو غیر انٹرایکٹو شکل میں نیچے دیکھ سکتے ہیں۔",
                        "noSupport": "آپ کا براؤزر یہ ویڈیو نہیں چلا سکتا۔"
                    },

                    // Uzbek
                    "uz": {
                        "desc":      "Қуйида ушбу мазмуннинг интерактив бўлмаган вариантини ҳам топишингиз мумкин",
                        "noSupport": "Сизнинг браузерингиз бу интерактив видеони ишлатолмайди."
                    },

                    // Vietnamese
                    "vi": {
                        "desc":      "Mời bạn xem phiên bản không tương tác dưới đây.",
                        "noSupport": "Trình duyệt của bạn không hỗ trợ xem video tương tác này."
                    }
                };
            }

            $('body').addClass('full-width-mode');

            /* CONFIG */
            var minWidth = 768;
            var useWhitelist = true; // Set to false to bypass browser whitelist
            var ctaBanner = true; // Set to false to hide CTA banner
            var serviceId = '<!--#echo var="SERVICE" -->';
            var displayMode = 'iframe'; // options: 'iframe', 'imageLink'

            var textValues = getTranslations(),
                currentLangText = (serviceId in textValues) ? textValues[serviceId] : textValues['en'],
                touchcastContainer = $('#touchcast-container');

            function browserIsWorthyOfTouchcast () {
                return (
                    ($('body').width() >= minWidth) &&
                    (window.matchMedia) &&
                    (Function.prototype.bind) &&
                    !(/Ovi|Symbian|Opera Mini/.test(navigator.userAgent))
                ) ||
                (/iPhone.*OS [^X345678]/.test(navigator.userAgent)) ||
                (/IE /.test(navigator.userAgent) && /Trident\/[^3]/.test(navigator.userAgent) );
            }

            function browserIsWhitelisted () {
                // Touchcast is broken on many old browsers, so we whitelist the
                // versions we know are working fine.

                if (!useWhitelist) return true;

                var ua = navigator.userAgent;

                // Chrome Desktop >= 30
                if (!/Android/.test(ua) && /Chrome\/[^12]/.test(ua)) return true;

                // Chrome Android or Android WebView >= 40
                if (/Android.*Chrome\/[^123]/.test(ua)) return true;

                // Firefox Desktop >=30, Windows or Macintosh
                if (/\((Windows|Macintosh).*Gecko\/.*Firefox\/[^12]/.test(ua)) return true;

                // Safari Desktop >= 6
                if (/\(Macintosh.*Version\/[^12345].*Safari/.test(ua)) return true;

                // Safari iOS, only iPad with iOS >= 8
                if (/iPad.*OS [^X34567]/.test(ua)) return true;

                // Safari iOS, only iPhone with iOS >= 9
                if (/iPhone.*OS [^X345678]/.test(ua)) return true;

                // IE Desktop > 7 && <= 10
                if (/IE /.test(ua) && /Trident\/[^3]/.test(ua)) return true;

                // IE Desktop >= 11
                if (/Trident\/[^3456]/.test(ua)) return true;

                // No match found
                return false;
            }

            function displayNotSupportedMsg() {
                touchcastContainer.html('<p><strong>' + currentLangText.noSupport + '</strong></p>');
            }

            function getTouchcastWidth() {
                return touchcastContainer.width();
            }

            function getTouchcastHeight() {
                return touchcastContainer.width() * 9 / 16;
            }

            function displayTouchcast () {
                if (displayMode == 'iframe') {
                    displayTouchcastInline();
                }
                else {
                    displayTouchcastLink();
                }
            }

            function displayTouchcastInline () {
                var html = '';

                if (ctaBanner) html +=
                    '<div class="touchcast-cta">Interactive Video ' +
                    '<span class="touchcast-cta__span">' +
                    'A new way of watching video – click or touch on the ' +
                    'panels when they appear</span></div>';

                html +=
                    '<iframe src="//bbc-vip.touchcast.com/sdk/demos/html5/bbc_v5/?performanceIds=<!--#echo var="TOUCHCAST_ID" -->&playfullscreen=1" ' +
                    'style="width:' + getTouchcastWidth() + 'px; ' +
                    'height:' + getTouchcastHeight() + 'px;" ' +
                    'class="touchcast-iframe" target="_blank" ' +
                    'frameborder="0" scrolling="no" allowfullscreen></iframe>' +
                    '<!-- <img src="<!--#echo var="IMAGE_URL" -->" /> -->' +
                    '<p><strong>' + currentLangText.desc + '</strong></p>';

                touchcastContainer.html(html);
            }

            function displayTouchcastLink () {
                touchcastContainer.html('<a href="//bbc-vip.touchcast.com/sdk/demos/html5/bbc_v5/?performanceIds=<!--#echo var="TOUCHCAST_ID" -->&playfullscreen=1" class="touchcast-holder" target="_blank"><img src="<!--#echo var="IMAGE_URL" -->" /></a><p><strong>' + currentLangText.desc + '</strong></p>');
            }

            function resizeTouchcast () {
                var touchcastIframe = touchcastContainer.find('iframe');
                $(touchcastIframe).width(getTouchcastWidth());
                $(touchcastIframe).height(getTouchcastHeight());
            }

            function conditionallyDisplayTouchcast () {
                if (browserIsWorthyOfTouchcast() && browserIsWhitelisted()){
                    // Insert Touchcast IFRAME
                    displayTouchcast();

                    // Listen to resize events
                    if (displayMode == 'iframe') {
                        $(window).resize(function() {
                            resizeTouchcast();
                        });
                    }
                }
                else {
                    displayNotSupportedMsg();
                }
            }

            conditionallyDisplayTouchcast();
        });
    </script>
<!--#else -->
    <!-- TOUCHCAST ID NOT FOUND -->
<!--#endif -->
