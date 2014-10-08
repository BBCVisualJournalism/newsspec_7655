<!--#if expr="$QUERY_STRING = /tcid=([a-zA-Z0-9_]+)/" -->
    <!--#set var="TOUCHCAST_ID" value="$1" -->
    <style>
        .touchcast-holder {}
    </style>
    <a href="<!--#echo var="TOUCHCAST_ID" -->" class="touchcast-holder" target="_blank">Launch fancy video</a>
<!--#else -->
    <!-- TOUCHCAST ID NOT FOUND -->
<!--#endif -->