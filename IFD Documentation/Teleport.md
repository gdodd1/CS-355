# IFD Teleportation Documentation

## TOC

- [Needs](https://github.com/gdodd1/CS-355/blob/main/IFD%20Documentation/Teleport.md#needs)
- [Code](https://github.com/gdodd1/CS-355/blob/main/IFD%20Documentation/Teleport.md#code)
- [Tags](https://github.com/gdodd1/CS-355/blob/main/IFD%20Documentation/Teleport.md#tags-explained)

## Needs

1. Vector or ULL of all areas the user has visited
2. Gamerule tag for random behavior or the ifd file author can "hardcode" where the user can teleport based on what their current room is, current inventory, etc.
3. User an be given a certain number of teleports per game or infinite, decided by author

## Code

```xml
<teleport>
  <behavior> random <behavior>
  <tpg> i <tpg>
  <start> 5 </start>
</teleport>
```

OR

```xml
<teleport>
  <behavior> 
    <items> Silver Bell </items>  
  <behavior>
  <tpg> 5 </tpg>
  <start> 0 </start>
<teleport>
```

## Tags Explained

### ```<behavior>```

- The ```<behavior>``` tag is how the ifd author describes how the user can use teleport, needing items, accessing rooms, etc

### ```<items>```

- The ```<items>``` tag is used to make the required items list. If the user doesn't have all of the items inside of the ```<items>``` tag, the user can't teleport

### ```<tpg>```

- The ```<tpg>``` tag simply means "teleports per game"
- If there is an integer between the ```<tpg>``` tags, then the variable will be set to that integer
- For an infinite amount of teleports per game, put "i" in the ```<tpg>``` tags
