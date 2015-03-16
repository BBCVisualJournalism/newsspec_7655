Newspsec 7655: Touchcast includes
================================

This project allows journalists to include touchcast promos into a CPS/Topcat page.

## How to use

Only the `touchcast-v2.inc` include should be used. The other files in this repo
are legacy files and should no longer be used.

The include will only show its content if the viewport width of the browser is
equal or event to 768px (this is the width of an iPad mini).

The include will check if the browser is supported by Touchcast (checking the
UserAgent string). If it's not, it will display a "Browser not supported"
message instead. The current whitelisted browsers are:

* Chrome Desktop >= 30
* Chrome Android or Android WebView >= 40
* Firefox Desktop >=30, Windows or Macintosh
* Safari Desktop >= 6
* Safari iOS, only iPad with iOS >= 8
* IE Desktop >= 10

## For /news

The touchcast ID needs to be passed in the querystring like this:

```
/news/special/2014/newsspec_7655/touchcast-v2.inc?tcid=XXX
```

## For World Service

You can additionally specify the translation by appending a `service` value:

```
/news/special/2014/newsspec_7655/touchcast-v2.inc?tcid=XXX&amp;service=XX

```

For the full list of values for the `service` parameter, refer to
[this Google Doc](https://docs.google.com/spreadsheets/d/1WSnJTuLx6-rgD8m77DVngoGcx18it_dbjqFAcprqJaA/edit#gid=0).
