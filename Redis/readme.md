# 🧠 1. What Redis REALLY is (Deep Understanding)

Redis = Remote Dictionary Server

But internally, it’s:

- A single-threaded event loop system
- Uses RAM for ultra-fast access (~microseconds)
- Stores data in specialized data structures (not just key-value)

👉 Think deeper:

System	Role
MySQL / MongoDB	Long-term memory
Redis	Short-term working memory

🔥 Why Redis is insanely fast<br>
- No disk I/O (mostly RAM)
- Single-threaded → no locking overhead
- Uses efficient structures like:
- hash tables
- skip lists
- linked lists

# ⚙️ 2. INSTALL REDIS & start redis
Redis is officially Linux-first,

```
sudo apt update
sudo apt install redis-server
```

Start Redis
```
redis-server
```
Open another terminal tab:
```
redis-cli
PING
```
👉 Output:
```
PONG
```
# 🧱 3. REDIS CORE ARCHITECTURE (IMPORTANT FOR INTERVIEWS)
Event Loop Model

Redis works like:
```
Client → Request → Event Loop → Execute → Response
```
👉 No threads → No race conditions → Fast

### Memory Storage

Redis stores data like:
```
Key → Value (String / List / Set / Hash / ZSet)
```
Internally:

Keys → Hash table<br>
Values → Encoded structures

###  NOTE: use ```info``` in redis CLI to get the server info

# 🔑 4. DATA STRUCTURES (DEEP LEVEL in redis cli)

### 🔸 1. Strings
By default, a single Redis string can be a maximum of 512 MB.

syntax
```
SET <key> <value> // return ok
GET <key> // returns value or nil
DEL <key> // returns int
```
use ``` KEYS * ``` to get all the keys in the currentr redis DB

basic commands

- working with existing Keys with XX and NX

    - NX
    - if key dosen't exist then key will be set and return ok
    - if key exist returns nil
    ```
    SET KEY VALUE NX
    ```
   - XX
   - return ok only if key exists
   - return nil if key dosen't exist
   ```
   SET KEY VALUE XX
   ```

- delete multiple keys
```
del <key_1> <key_2> // returns int (number of keys deleted)
```
- set and get multiple keys

```
> MSET key_1 "Value_1" key_2 "value_2" key_3 "value_3"
OK
> MGET key_1  key_2  key_3 
1) "Value_1"
2) "value_2"
3) "value_3"
```

- strings as counter
```
> SET total_crashes 0
OK
> INCR total_crashes
(integer) 1
> INCRBY total_crashes 10
(integer) 11
```

Internal:<br>
Stored as SDS (Simple Dynamic String)

👉 Supports:

- counters
- JSON (stringified)
- caching

### 🔸JSON

The first JSON command to try is JSON.SET, which sets a Redis key with a JSON value. JSON.SET accepts all JSON value types. This example creates a JSON string:

```
> JSON.SET bike $ '"Hyperion"'
OK
> JSON.GET bike $
"[\"Hyperion\"]"
> JSON.TYPE bike $
1) "string"
```

##### Note how the commands include the dollar sign character $. This is the path to the value in the JSON document (in this case it just means the root).

Here are a few more string operations. JSON.STRLEN tells you the length of the string, and you can append another string to it with JSON.STRAPPEND.

```
> JSON.STRLEN bike $
1) (integer) 8
> JSON.STRAPPEND bike $ '" (Enduro bikes)"'
1) (integer) 23
> JSON.GET bike $
"[\"Hyperion (Enduro bikes)\"]"
```

Numbers can be incremented and multiplied:

```
> JSON.SET crashes $ 0
OK
> JSON.NUMINCRBY crashes $ 1
"[1]"
> JSON.NUMINCRBY crashes $ 1.5
"[2.5]"
> JSON.NUMINCRBY crashes $ -0.75
"[1.75]"
> JSON.NUMMULTBY crashes $ 24
"[42]"
```

#### JSONPath support

RedisJSON v2.0 introduced JSONPath support

If you want to include double quotes in a query from the CLI, enclose the JSONPath within single quotes. For example:

```
JSON.GET store '$.inventory["mountain_bikes"]'
```

#### JSONPath syntax 

The following JSONPath syntax table was adapted from Goessner's path syntax comparison.

| Syntax element	| Description |
|-------------------|-------------|
|$	| The root (outermost JSON element), starts the path.|
|. or []	| Selects a child element.|
|..	|Recursively descends through the JSON document.|
|*	|Wildcard, returns all elements.|
|[]	|Subscript operator, accesses an array element.|
|[,] |	Union, selects multiple elements.|
|[start:end:step] |	Array slice where start, end, and step are index values. You can omit values from the slice (for example, [3:], [:8:2]) to use the default values: start defaults to the first index, end defaults to the last index, and step defaults to 1. Use [*] or [:] to select all elements.|
|?() |	Filters a JSON object or array. Supports comparison operators (==, !=, <, <=, >, >=, =~), logical operators (&&, ||), and parenthesis ((, )).|
|() |	Script expression. |
|@ |	The current element, used in filter or script expressions.|

json Path allowes to edit the json data in between

### 🔸Lists (Queue / Stack)

Redis lists are linked lists of string values. Redis lists are frequently used to:

- Implement stacks and queues.
- Build queue management for background worker systems

Examples <br>
#### Treat a list like a queue (first in, first out):

Syntax
```
$> LPUSH <variable_key> <Value_1>
(integer) 1
$> LPUSH <variable_key> <Value_2> 
(integer) 2
$> RPOP <variable_key>
<Value_1>
$> RPOP <variable_key>
<Value_2>
```

#### Treat a list like a stack (first in, last out):

Syntax
```
$> LPUSH <variable_key> <Value_1>
(integer) 1
$> LPUSH <variable_key> <Value_2> 
(integer) 2
$> LPOP <variable_key>
<Value_2>
$> LPOP <variable_key>
<Value_1>
```
NOTE: you can even use RPUSH RPOP instead. push and pop can be done from both the end.
#### Check the length of a list:
```
$> LLEN <variable_key>
(integer) 0
```
#### Atomically pop an element from one list and push to another:

```
> LPUSH <variable_key_1> <Value_1>
(integer) 1
> LPUSH <variable_key_1> <Value_2>
(integer) 2
> LMOVE <variable_key_1> <variable_key_2> LEFT LEFT
"<Value_2>"
> LRANGE <variable_key_1> 0 -1
1) "<Value_1>"
> LRANGE <variable_key_2> 0 -1
1) "<Value_2>"
```

#### To limit the length of a list you can call LTRIM:
and the LRANGE command extracts ranges of elements from lists:
```
> DEL <variable_key_1>
(integer) 1
> RPUSH <variable_key_1> <Value_1> <Value_2> <Value_3> <Value_4> <Value_5>
(integer) 5
> LTRIM <variable_key_1> 0 2
OK
> LRANGE <variable_key_1> 0 -1
1) "<Value_1>"
2) "<Value_2>"
3) "<Value_3>"
```

#### Blocking operations on lists 
Lists have a special feature that make them suitable to implement queues, and in general as a building block for inter process communication systems: blocking operations.

Imagine you want to push items into a list with one process, and use a different process in order to actually do some kind of work with those items. This is the usual producer / consumer setup, and can be implemented in the following simple way:

To push items into the list, producers call LPUSH.
To extract / process items from the list, consumers call RPOP.
However it is possible that sometimes the list is empty and there is nothing to process, so RPOP just returns NULL. In this case a consumer is forced to wait some time and retry again with RPOP. This is called polling, and is not a good idea in this context because it has several drawbacks:

Forces Redis and clients to process useless commands (all the requests when the list is empty will get no actual work done, they'll just return NULL).
Adds a delay to the processing of items, since after a worker receives a NULL, it waits some time. To make the delay smaller, we could wait less between calls to RPOP, with the effect of amplifying problem number 1, i.e. more useless calls to Redis.
So Redis implements commands called BRPOP and BLPOP which are versions of RPOP and LPOP able to block if the list is empty: they'll return to the caller only when a new element is added to the list, or when a user-specified timeout is reached.

This is an example of a BRPOP call we could use in the worker:

```
> RPUSH <variable_key_1> <Value_1> <Value_2>
(integer) 2
> BRPOP <variable_key_1> 1
1) "<variable_key_1>"
2) "<Value_2>"
> BRPOP <variable_key_1> 1
1) "<variable_key_1>"
2) "<Value_1>"
> BRPOP <variable_key_1> 1 // keeping 1 sec timeout
(nil)
(2.01s)
> BRPOP <variable_key_1> 5 // keeping 5 sec timeout
(nil)
(6.01s)
```
It means: "wait for elements in the list bikes:repairs, but return if after 1 second no element is available".

Note that you can use 0 as timeout to wait for elements forever, and you can also specify multiple lists and not just one, in order to wait on multiple lists at the same time, and get notified when the first list receives an element.

A few things to note about BRPOP:

Clients are served in an ordered way: the first client that blocked waiting for a list, is served first when an element is pushed by some other client, and so forth.
The return value is different compared to RPOP: it is a two-element array since it also includes the name of the key, because BRPOP and BLPOP are able to block waiting for elements from multiple lists.
If the timeout is reached, NULL is returned.

#### NOTE: The maximum length of a Redis list is 2^32 - 1 (4,294,967,295) elements.

### 🔸Sets (Unique values)
A Redis set is an unordered collection of unique strings (members). You can use Redis sets to efficiently:

Track unique items (e.g., track all unique IP addresses accessing a given blog post).
Represent relations (e.g., the set of all users with a given role).
Perform common set operations such as intersection, unions, and differences.

Examples 
Store the sets of bikes racing in France and the USA. Note that if you add a member that already exists, it will be ignored.

```
> SADD bikes:racing:france bike:1
(integer) 1
> SADD bikes:racing:france bike:1
(integer) 0
> SADD bikes:racing:france bike:2 bike:3
(integer) 2
> SADD bikes:racing:usa bike:1 bike:4
(integer) 2
```
Check whether bike:1 or bike:2 are racing in the US.
```
> SISMEMBER bikes:racing:usa bike:1
(integer) 1
> SISMEMBER bikes:racing:usa bike:2
(integer) 0
```
Which bikes are competing in both races?
```
> SINTER bikes:racing:france bikes:racing:usa
1) "bike:1"
```
How many bikes are racing in France?
```
> SCARD bikes:racing:france
(integer) 3
```

### 🔸4. Hashes (Objects)
