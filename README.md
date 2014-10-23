Newspsec 7655: Touchast includes
================================

This project allows journalists to include touchcast promos into a CPS/Topcat page.

## For World Service

All World Service sites are fully responsive so require a different solution to /news.

Only the `touchcast-responsive.inc` include is used.

This needs to pass via the querystring the touchcast id, the image url and what service is being used.

```
/news/special/2014/newsspec_7655/touchcast-responsive.inc?responsive=true&tcid=XXX&imageurl=XXXX&service=XXXX
```

* tcid : The touchcast id to link to
* image url : the URL of the image to use (this image needs to be published seperately via Topcat or CPS)
* service : this will inform the include which translation to use

This include will only show its content if the viewport width of the browser is equal or event to 768px (this is the width of an iPad mini).

A key difference between the desktop site and the responsive site is that the responsive site sets meta viewport scale to be 1 to 1.  This means that the page behaves responsively.  The desktop does not have this setting applied to it, so the browser will scale the site down to fit into the device's viewport.

## For /news 

Until the News site is fully responsive we have to provide touchcasts to the desktop only site.  Right now only mobiles are redirected to the responsive site.  This means that tablets and desktop browsers get the desktop site.  Because of this we use two includes for touchcast:

### desktop include

```
/news/special/2014/newsspec_7655/touchcast.inc?tcid=XXX&imageurl=XXXX
```

This include does two things:

* Shows the link to the include
  * tcid : The touchcast id to link to
  * image url : the URL of the image to use (this image needs to be published seperately via Topcat or CPS)
* Hides the include for responsive

### responsive include

```
/news/special/2014/newsspec_7655/not-supported.inc?responsive=true
```

This include displays a message telling the user the touchcast content is not supported by their device.  As this include will also be displayed in the desktop site, the desktop include hides this message.


