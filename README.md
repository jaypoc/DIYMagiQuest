# DIY MagiQuest Implementation

## Why?
On a recent family vacation to the Great Wolf Lodge, we waited until our last day there to check out their MagiQuest experience. My seven year old daughter enjoyed running around the hotel looking for artifacts and interacting with their quest system. We purchased the wand for the game, but after we left we wondered if we would be able to use it again (We live over 5 hours away from any MagiQuest locations I'm familiar with).

I decided to look into building a system that would allow us to use the wand to interact with artifacts at home as we did at the lodge. 

Here's what I came up with.

## Hardware

* HiLetgo ESP8266 NodeMCU CP2102 ESP-12E ([link](https://www.amazon.com/dp/B0CNYJS6V7?psc=1&ref=ppx_yo2ov_dt_b_product_details))
* DY-SV5V MP3 Playback Module  ([link](https://www.amazon.com/dp/B07YFPBGF8?psc=1&ref=ppx_yo2ov_dt_b_product_details))
* TSOP4838 IR Reciever ([link](https://www.amazon.com/dp/B09BTD69C3?psc=1&ref=ppx_yo2ov_dt_b_product_details))
* 5W 8Ohm Mini-Speaker ([link](https://www.amazon.com/dp/B0C5HRRHRL?psc=1&ref=ppx_yo2ov_dt_b_product_details))

Follow the documentation, as different versions of these components may have different pinouts, but heres' how I connected it:

* IR receiver signal is connected to pin ```D0``` of the NodeMCU
* MP3 module is controlled over UART from pin ```TX```on the NodeMCU to ```IO1/RX``` on the module.
* Both are powered from the board's 3.3v connections and ground


_This is the hardware I am using. I do  have some plans to experiment with different hardware (such as swapping out the 38KkHz IR receiver with a 36kHz one). If you find other hardware that works, please share it._

## Future Ideas

* 3D print cool objects to interact with
* Connect LEDs to light up the objects 
* Connect Servos to animate the objects

If you have any other cool ideas, please let me know!

## Disclaimer

This project is an independent, non-commercial endeavor created for educational and experimental purposes only. It is not affiliated with, endorsed by, or sponsored by Great Wolf Lodge, MagiQuest, or any related entities. The use of the MagiQuest wand technology is subject to the terms and conditions set forth by its respective owners.

While efforts have been made to ensure the accuracy and functionality of the code, the developer(s) make no guarantees or warranties regarding its suitability for any particular purpose. By using this code, you agree that the developers are not liable for any damages, including but not limited to direct, indirect, incidental, special, or consequential damages arising out of the use or inability to use the code.

It is the responsibility of the user to comply with all applicable laws and regulations, including intellectual property rights, when utilizing this code. The developers disclaim any liability for the misuse or unauthorized use of this code by third parties.
