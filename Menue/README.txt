### About
This is a management system for a card game called "Slay the Spire".
It is used to view, maintain and sort cards and their effects.

### Data sets
- There are three characters: Ironclad, Silent, Defect.
- There are five card types: Attack, Skill, Power, Status and Curse.
- Only cards of the card type "Attack" have a damage number.
- Any card can have no, one or multiple effects.


### Known bugs:
- When sorting by column "effects", values might seem out of order.
    This is caused by different ASCII values of lower and uppercase Characters (e.g.: none - Vulnerable)
- When importing data, data entries directly between two empty comment lines are not recognized.
    e.g.:
    *
    data/data/data/...
    *

    This is because the newline character immediately follows the comment indicator *.
