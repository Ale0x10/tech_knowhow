## Scematic Conventions:

At a very high level, schematics across most of the “western world” are read from left to right, the same as we read the text in our languages.
Signals flow from left to right, and voltage potentials generally (for voltage regulation) decrease from left to right. Currents usually flow from top to bottom. 

source: https://resources.altium.com/p/creating-elegant-and-readable-schematics

## Checklist:

Read your schematics from left to right: This means you should try to arrange components with inputs in the left side of the sheet, and connect components in succession flowing to the right side of the sheet.
Group components that are part of the same circuit into small areas: There’s no need to send wires back-and-forth across your schematic sheets as the design can get very messy. Keep the components that are part of a single circuit in one area whenever possible.
Try to avoid crossing wires in the schematic: When crossing wires, you might accidentally make a connection between two nets that you didn’t intend. In addition, someone might read the schematic and see a connection where you did not intend. It’s best to try and avoid crossing wires where possible.
Use net names and ports instead of crossing wires: You can eliminate a lot of crossed wires between components by using net names inside your schematics. We’ll look at an example schematic below to see how this can be done with net names in a schematic sheet.
Use power and ground ports: Instead of using the input or output port symbols for power/ground, use the built-in power and ground port symbols. These are standard symbols that clearly indicate power and ground connections within a sheet and between sheets.
Don’t be afraid to use multiple sheets: If you think you need to place circuits into different sheets, then your intuition is probably correct. It’s okay to try and place a big circuit in a single sheet, but sometimes the circuits just get too large to manage. When this happens, you can define a link between two sheets using a port.
Try to mostly use net names and ports on large ICs: Some ICs can have hundreds of pins, and each of these will connect somewhere else in the design. It’s better to place net names and ports to define connections on large ICs rather than routing too many wires

## Weitere Tipps:

Obwohl es sehr praktisch wäre, gibt es keine einheitlichen Richtlinien für die Auswahl von Komponenten in jedem Design. Wenn dies der Fall wäre, würden Computer (mit KI) ständig automatisch Leiterplatten erstellen! 
Heute ist der Fall, dass Designer oft selbst Komponenten auswählen müssen, diese in einem Schaltplan verdrahten und das PCB-Layout fertigstellen.
Die Anzahl der verschiedenen Komponententypen ist relativ gering; insgesamt lassen sich wahrscheinlich etwa 20 Kategorien von Komponenten unterscheiden. 

    Ports should only be used to make connections between sheets, not within the same sheet.
    There are two points where some wires in the schematic cross each other, making it appear as if there is a connection between these wires. It’s best to try and arrange schematics so that there are no crossed wires.
    The output power (+3V3_Dig) was defined as an output signal port instead of a power port. A power port should be used instead.
    A long GND net connects all the ground points along the bottom of the circuit. It would be better to use a ground port on these connections.

### Search components:
Open Manufacturer Part Search panel to find components for your design. 
Inside Altium Designer the Components panel, it’s important to note that this panel only shows the components you have installed on your local computer. 
https://octopart.com/de (also for eval boards) ( One important set of information you’ll see on this page is a list of distributors and some inventory numbers in a table. This information is very important for designers. If you plan to use a particular component in your design, you want to make sure that you can actually purchase it from a distributor for a fair price. Be sure to check that a component you want to use is in-stock before you add it to your design.)
When you’re looking at component data from distributors, Octopart, or a similar parts search engine, pay attention to some basic information in your search results:

    Stock: The available stock for a component should be large enough that you could do a repeated run if needed.
    Authorized vs. unauthorized distributors: You should always opt to buy from an authorized distributor. An unauthorized distributor may be a reseller, or they could be dealing in counterfeit components.
    Minimum order quantity (MOQ): Some components are only for sale at high volume (10,000 or more units). Usually, if you find a component with high MOQ, you can also find the same component from another distributor with no MOQ.
    Lifecycle: All electronic components will eventually go obsolete and will be replaced with newer versions. It’s generally a good idea to use newer parts in your design, although there are some cases where you can use older components without any problems.
    Price: Distributors are transparent about their pricing, so you’ll be able to shop around to get the best price for your required order quantity.

https://uploads.teachablecdn.com/attachments/uAaXgrgMTqGiaJzDafZr_pasted+image+0.png
