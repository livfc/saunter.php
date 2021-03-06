<?php
  $sites = array(
    "development" => "http://saucelabs.com",
    "qa" => "http://qa.mycompany.com",
    "staging" => "http://stage.mycompany.com",
    "production" => "http://www.mycompany.com"
  );

  $timeout = 45; // seconds
  $GLOBALS['timeouts'] = array(
      "seconds" => $timeout,
      "ms" => $timeout * 1000,
      "str_ms" => (string) $timeout * 1000
  );

  $GLOBALS['settings'] = array(
    "sauce.ondemand" => false
  );

  $GLOBALS['settings']['webserver'] = $sites["development"];
  if ($GLOBALS['settings']['sauce.ondemand'])
  {
      require_once("saucelabs.inc");

      $GLOBALS['settings']['browser'] = json_encode(array(
          "username" => $GLOBALS['saucelabs']['username'],
          "access-key" => $GLOBALS['saucelabs']['key'],
          "os" => "Windows 2003", 
          "browser" => "firefox",
          "browser-version" => "3.6."
      ));
      $GLOBALS['settings']['seleniumserver'] = "ondemand.saucelabs.com";
      $GLOBALS['settings']['seleniumport'] = 4444;

  } else {
      $GLOBALS['settings']['browser'] = "*firefox";
      $GLOBALS['settings']['seleniumserver'] = "localhost";
      $GLOBALS['settings']['seleniumport'] = 4444;
  }
  
  date_default_timezone_set('America/New_York');
  $GLOBALS['settings']['logname'] = 'logs/' . date('Y-m-d-h-i-s') . '.log';
?>