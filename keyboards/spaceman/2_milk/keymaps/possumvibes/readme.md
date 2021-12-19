# ~~Norse Horse Morse~~ Milk 2%
Why am I calling it Norse Horse Morse? Because when I first mentioned it to my friends, they challenged me to use it for morse code. Norse came from a TYPO IN THE GROUP CHAT, so of coure the final form of my 2% Milk needs to have norse runes for legends, and from there, it was a series of chaotic escalations of rhyming things that vaguely made sense until we threw horse on there too. 

(It's important to note that we collectively share one brain cell that just bounces between our brains like the chakram slicing an apple across town.)

So I've got a morse layer.
I'm going to draw legends onto some cheap DSA caps.
and 
critically
I'm going to draw some horses on the outside case.

Norse! Horse! Morse! Milk 2%!!

# The Layout
## Base Layer

```
,--------.
| Raise/ |
| flash  |
|--------+
| Lower/ |
| ENTER  |
`------- '
```

Both keys are LTs. flash sends `qmk flash \n`, for quick flash purposes; Enter is for the occasion where I hit the reset button too quickly on my main keyboard and need to Just Hit Enter to complete the flash.

## Lower
```
,-------.
| RESET |
|-------+
|       |
`-------'
```

For quick Reset access.

## Raise
MORSE TIME MORSE TIME

```
,-------.
|       |
|-------+
| Morse |
`-------'
```

Morse is a custom Tap-Hold that sends `.` on tap and `-` on hold.
Norse Horse MORSE.

## Hardware Features

### LEDs
I toasted one of the LEDs during the build and absolutely cannot be bothered to fix that. The one functional per-key LED on the board runs the Rainbow Mood animation by default. 

##
With the current set of space-saver config settings, the keymap is at 62%. There's plenty of room to add more LED animation or go absolutely bananas with combos and oneshot layers. 

Overall: a fun build, an easy keymap to replicate, and a very charming final result!
