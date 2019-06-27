# ANT FeatherWing

## Usage
You can order this board using the gerber and BOM (sockets/pins not included in the BOM.) We ordered ours from Seeedstudio and they work fantastic.

## Limitations
This board is restricted to ASYNC mode with the ANT radio. This is to optimize the pin
usage since the ANT radio is the SPI master and Arduino does not support being a SPI
slave. There will be an additional breakout board published in which those interested
in using SPI will have those pins broken out.

## Drivers
The board can use any generic ANT driver but we recommend [ant-arduino](https://github.com/cujomalainey/ant-arduino)
but you will have to set all pins manually other than TX/RX. If you are looking for ANT+ support we recommend
[antplus-arduino](https://github.com/cujomalainey/antplus-arduino).

## Pin Mapping
|Name   |D52 Pin|Feather Pin|
|-------|-------|-----------|
|RESET  |P207   |33         |
|SLEEP  |P202   |27         |
|SUSPEND|P215   |4          |
|BR1    |P210   |32         |
|BR2    |P213   |21         |
|BR3    |P212   |14         |
|RX     |P218   |17         |
|TX     |P217   |16         |

## Renderings

### Layout Rendering
![Layout](https://raw.githubusercontent.com/reeganm/ANT-FeatherWing/master/images/kicad.PNG)

### Print Examples
![Side by side](https://raw.githubusercontent.com/reeganm/ANT-FeatherWing/master/images/sidebyside.jpg)

### HUZZAH32 Stack
![Stacked](https://raw.githubusercontent.com/reeganm/ANT-FeatherWing/master/images/esp32_stack.jpg)

## Questions/Feedback

Questions about this project should be posted to http://groups.google.com/group/ant-api?pli=1 Be sure to provide as much detail as possible (e.g. what radios, firmware versions, configuration and code).