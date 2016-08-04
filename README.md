# ml-fota

## Required

* ml-wifi

## API

``` js
/* Download the fota image. */

__fota(
  url, // string
)

```

## Don't forget to Change the Bootloader.

## Example

``` js

  __wifi({
    mode: 'station', // default is station
    auth: 'PSK_WPA2',
    ssid: 'Input your ssid',
    password: 'Input your password',
  });

  global.eventStatus.on('wifiConnect', function() {
      __fota("http://cdn.mediatek.com/firmwares/PuxQFhlHKM2B/36c8248e37161cc333a6cbb6f2586a42/output.bin");
  });

```
