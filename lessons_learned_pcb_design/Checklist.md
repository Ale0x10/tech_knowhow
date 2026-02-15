## Questions before designing the scematic and PCB:   

Do you know which types of circuits you’ll need in each section of your PCB? Each of these circuits will need to be considered when building schematics.
    Will any of your circuits need to be repeated in multiple places in the design? This can motivate using hierarchical schematics instead of arranging everything as flat schematics.
    Do you know which power sources you need on various components? Some components, particularly large digital ICs, require multiple voltage levels to operate properly, and these should be considered early.
    Will there be more than one ground net in the design? Small battery-powered devices may not need multiple ground nets, but designs like large power regulators or industrial equipment will regularly use multiple ground nets.




### Sources:

https://resources.altium.com/p/how-hierarchical-schematic-design-can-help-your-next-pcb-schematic-layout
https://www.globalwellpcba.com/de/warmemanagement-der-leiterplatte/

### Additional:

A simple rule of thumb is this: if the design includes circuit blocks that are repeated in multiple instances in the design, it’s probably a good idea to use a hierarchical schematic structure. This doesn’t mean that all of your schematics will need to be repeated. However, the hierarchical structure is very useful in that it makes repetition easy.


### Good to know:
In Altium Designer, these connections between schematic sheets are created using two objects: ports and harnesses. A port is an object that is used to denote a single connection between two sheets. The best way to think of a harness is like a connection of multiple ports. 