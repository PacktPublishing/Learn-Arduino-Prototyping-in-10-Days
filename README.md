# Learn Arduino Prototyping in 10 days
This is the code repository for [Learn Arduino Prototyping in 10 days](https://www.packtpub.com/hardware-and-creative/learn-arduino-prototyping-10-days?utm_source=github&utm_medium=repository&utm_campaign=9781788290685), published by [Packt](https://www.packtpub.com/?utm_source=github). It contains all the supporting project files necessary to work through the book from start to finish.

## About the Book
The single-chip computer board Arduino is small in size but vast in scope, capable of being used for electronic projects from robotics through to home automation. The most popular embedded platform in the world, Arduino users range from school children to industry experts, all incorporating it into their designs.

Arduino Development Cookbook comprises clear and step-by-step recipes that give you the toolbox of techniques to construct any Arduino project, from the simple to the advanced. Each chapter gives you more essential building blocks for Arduino development, from learning about programming buttons through to operating motors, managing sensors, and controlling displays. Throughout, you'll find tips and tricks to help you troubleshoot your development problems and push your Arduino project to the next level!
## Instructions and Navigation
All of the code is organized into folders. Each folder starts with a number followed by the application name. For example, Chapter02.



The code will look like the following:
```
// Signal a quick LOW just before giving a HIGH signal
digitalWrite(3, LOW);
delayMicroseconds(2);

// After 2 micro-seconds of LOW signal, give a HIGH signal  
// to trigger the sensor
digitalWrite(3, HIGH);
// Keep the digital signal HIGH forat least 10 micro-seconds
// (required by HC-SR04 to activate emission of ultra-sonic 
// waves)
delayMicroseconds(10);

// After 10 micro-seconds, send a LOW signal
digitalWrite(3, LOW);

```



## Related Products
* [Learning C for Arduino](https://www.packtpub.com/hardware-and-creative/learn-arduino-prototyping-10-days?utm_source=github&utm_medium=repository&utm_campaign=9781788290685)

* [Arduino Electronics Blueprints](https://www.packtpub.com/hardware-and-creative/learn-arduino-prototyping-10-days?utm_source=github&utm_medium=repository&utm_campaign=9781788290685)

* [Arduino Development Cookbook](https://www.packtpub.com/hardware-and-creative/learn-arduino-prototyping-10-days?utm_source=github&utm_medium=repository&utm_campaign=9781788290685)

### Suggestions and Feedback
[Click here](https://docs.google.com/forms/d/e/1FAIpQLSe5qwunkGf6PUvzPirPDtuy1Du5Rlzew23UBp2S-P3wB-GcwQ/viewform) if you have any feedback or suggestions.
