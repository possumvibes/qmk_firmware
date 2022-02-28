# The Possumvibes Keymap

A featureset designed around holding keys down as little as possible, keeping finger use balanced across all layers, and reducing fast and/or repetitive thumb movement as much as possible. This layout leverages combos, home row mods, smart layers, one- and two-shot (*n*-shot, to be specific) mods, locking mods, and one-tap swappers to reduce the number of layer tap-holds needed. 

The layout itself is defined per keyboard, but the core 3x5+2 layout is defined in blocks of five keys using Drashna's wrappers approach. My comfortable range of motion on MX boards is two thumb keys per side, and I'm far more comfortable using thumbs for taps (including thumb-only combos) than holding thumbs. Nav, on my left home thumb, is my only thumb tap-hold, and all other layers are accessed via combo, direct toggle, or alpha LT.

### Locking Mods
These are "locking" toggle-able mods with a defined cancel/continue key list. I use these on my nav layer, specifically for hands-off text editing in cases where I'd otherwise need to keep a mod held (e.g., to select text with Ctrl+Shift+arrow, I can tap into my nav layer, tap locking Ctrl and Shift, and then tap or hold the arrow as long as needed.) My usage of them is very narrow--anything besides the navigation keys (arrows, home, end) and the locking mods themselves will reset the toggled mods.

### N-shot mods
These are an adaptation of the Callum oneshot mods that use array structure and leave the mod "sticky" for a specified *n* amount of keypresses (practically speaking, this means one-shot mods plus a two-shot Ctrl.) Like the callum implementation, "ignore" and "cancel" keys are defined in separate functions.

I keep these on my nav layer, which is accessible from any layer, for use on my non-alpha layers. I currently prefer home-row mods on alpha and the flexibility of either home row or n-shots with my number/symbol/function keys.

### Smart Layers
Smart layers are, functionally, caps word but for your layer of choice, with cancel keys defined. I have NumMode and FuncMode, each of which allow me to keep typing numbers or f-keys respectively until I hit a cancel key. These are likewise born out of a passionate dislike of holding layer toggles or using thumbs for any kind of fast or repeated movement (*especially* involving holding layer toggles). These are very much inspired by the T-34 layout, linked in the code influences section.

### Swapper
Another Callum feature, modified to accept a reverse trigger and action. I am currently using this for Alt+Tab and Ctrl+Tab, with my SW_REV custom keycode acting as the Swapper-Reverse trigger key for both. The modifier is released with the press or release of another non-swapper key (the releasing keypress is swallowed and does not get handled after cancelling the swapper). I keep mine on the nav layer and access them primarily via my nav layer-tap, so releasing the layer tap-hold also releases the swapper modifier.

### Combos
I use combos very heavily for punctuation and shortcuts. 
| Keys                       | Output          | | Keys                     | Output               |
| -------------------------- | --------------- |-| ------------------------ | -------------------- |
| <kbd>Ent</kbd><kbd>B</kbd> | <kbd>SYS</kbd>  | | <kbd>R</kbd><kbd>T</kbd> | <kbd>BACK/FWD</kbd>  |
| <kbd>Spc</kbd><kbd>N</kbd> | <kbd>_</kbd>    | | <kbd>Y</kbd><kbd>U</kbd> | <kbd>UNDO/REDO</kbd> |
| <kbd>E</kbd><kbd>R</kbd>   | <kbd>SAVE</kbd> | | <kbd>K</kbd><kbd>M</kbd> | <kbd>TAB</kbd>  |
| <kbd>X</kbd><kbd>C</kbd>   | <kbd>#</kbd>    | | <kbd>S</kbd><kbd>D</kbd> | <kbd>COPY</kbd>      |
| <kbd>C</kbd><kbd>V</kbd>   | <kbd>/</kbd>    | | <kbd>D</kbd><kbd>F</kbd> | <kbd>PASTE</kbd>     |
| <kbd>M</kbd><kbd>,</kbd>   | <kbd>-</kbd>    | | <kbd>S</kbd><kbd>F</kbd> | <kbd>CUT</kbd>       |
| <kbd>,</kbd><kbd>.</kbd>   | <kbd>\*</kbd>   | | <kbd>J</kbd><kbd>K</kbd> | <kbd>NUMMODE</kbd>   |
| <kbd>M</kbd><kbd>.</kbd>   | <kbd>@</kbd>    | | <kbd>K</kbd><kbd>L</kbd> | <kbd>FUNMODE</kbd>   |

I use combos between the home thumbs (<kbd>Enter</kbd> and <kbd>Space</kbd>) and the alpha keys directly above them (<kbd>B</kbd> and <kbd>N</kbd> respectively)as a pseudo-third thumb key per side. (On a keyboard where horizontal thumb combos are possible for me, these thumb combos will get revamped.)
[Combos KLE](http://www.keyboard-layout-editor.com/#/gists/4c081803e87b4e4e6b83b25dc6c86fb3)

### Layout

The base layout that all my boards use can be found here: [Keyboard Layout Editor](http://www.keyboard-layout-editor.com/#/gists/79a1cfb7764af21fc37f416259811919). There are variations between boards based on encoders, column count, thumb key arrangement, etc, but the core alphas viewable here are those defined in `wrappers.h`.

### Navigating the userspace
 
 `/features` folder holds my custom features.

`possumvibes.h` is the primary file imported into each keyboard's keymap and defines a few functions that `possumvibes.c` implements.

`keycodes.h` holds all the enums, custom keycodes, and key aliases, while  `wrappers.h` holds the layer blocks of keycodes to be applied reusably per keymap.

`combos.def` holds the combo definitions for the `gboards` implementation, and `combos.c` holds the functions for per-combo combo terms, the must-tap and must-hold configuration.
 
`process_records.c` holds the `process_record_user` implementation and handles all the userspace-defined custom keycodes. It defines `process_record_keymap` weakly so that individual keymaps can have additional key definitions or override the userspace definitions.
 
`encoders.h` holds the `encoder_update_user` function, and `tap_holds.c` holds the `get_tapping_force_hold` and `get_tapping_term` functions.

Last but not least, this readme has links to all my current board keymaps at the end so it's easier to see how these get used in practice.

### Code Influences (alphabetically and non-comprehensively)
- Callum's [userspace](https://github.com/qmk/qmk_firmware/tree/master/users/callum) - Oneshots, swappers
- Drashna's [userspace](https://github.com/qmk/qmk_firmware/tree/master/users/drashna) - Wrappers, layout override functions, and a whole lot more
- Jonas H's [T34 layout](https://www.jonashietala.se/blog/2021/06/03/the-t-34-keyboard-layout/) - Numword
- Manna-Harbour's [Miryoku layout](https://github.com/manna-harbour/miryoku) - The actual starting point of this layout, many iterations ago
- Patrick Getreuer's [QMK articles](https://getreuer.info/posts/keyboards/index.html) (aka How I Learned To Stop Worrying And Love Arrays)
- The Hands Down Discord server, for some hella cool alpha layouts and different ways of approaching layout balance at the layer and layout levels

### Possumvibes Keyboard Vault
Possibly even up to date!

- Kyria (38 keys; [Readme](../../keyboards/splitkb/kyria/keymaps/possumvibes/readme.md)): A 44-46 key MX split from [SplitKb](https://splitkb.com/). Uses this userspace keymap.
- Osprette (34 keys; [Readme](../../keyboards/osprette/keymaps/possumvibes/readme.md)): A choc-spaced pinky cluster board from [S'mores' Boards](https://www.smoresboards.com/). Uses this userspace keymap.
- Fissure (36-40 keys; [Readme](../../keyboards/fissure/keymaps/possumvibes/readme.md)): My current daily driver! A choc-spaced board with two keys in each 6th col for steno. Uses this userspace keymap.
- 2% Milk (2 keys; [Readme](../../keyboards/spaceman/2_milk/keymaps/possumvibes/readme.md)): A 2% macropad from [Keyhive](https://keyhive.xyz/shop/milk).
