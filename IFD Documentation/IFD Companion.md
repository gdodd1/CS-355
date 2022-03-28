# Companion

## Companion needs

1. Name
1. Type
    - Cat
    - Dog
    - Person
    - Etc.
1. Action

Companion should be able to help the user in some way.

- Speak
  - Tell the user their current room / rooms visited
- Smell
  - Know useful items (add useful tag in item parser and documentation) and be able to tell the user the useful items in the room
- Retrieve Items the user previously had
  - Ex. Left the Silver Bell in room 1 and the user wants it back in room 3, the companion could "go get it" for the user

## Code

```xml
<companion>
  <type> Dog </type>
  <name> Clifford </name>
  <action> Smell </action
</companion
```

OR

```xml
</companion type="Dog" name="Clifford action="Smell"> 
```
