# ANT FeatherWing

## Usage
You can order this board using the gerber and BOM (sockets/pins not included in the BOM.) We ordered ours from Seeedstudio and they work fantastic.

## Limitations
This board is restricted to ASYNC mode with the ANT radio. This is to optimize the pin
usage since the ANT radio is the SPI master and Arduino does not support being a SPI
slave. There will be an additional breakout board published in which those interested
in using SPI will have those pins broken out.

## Pin Mapping
|Name   |D52 Pin|Feather Pin|
|-------|-------|-----------|
|RESET  |P207   |33         |
|SLEEP  |P202   |27         |
|SUSPEND|P215   |4          |
|BR1    |P210   |32         |
|BR2    |P213   |21         |
|BR3    |P212   |14         |

## Renderings

### Layout Rendering
![Layout](https://raw.githubusercontent.com/reeganm/ANT-FeatherWing/master/images/kicad.PNG)

### Print Examples
![Side by side](https://raw.githubusercontent.com/reeganm/ANT-FeatherWing/master/images/sidebyside.jpg)

### HUZZAH32 Stack
![Stacked](https://raw.githubusercontent.com/reeganm/ANT-FeatherWing/master/images/esp32_stack.jpg)