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

### 🔸Hashes (Objects)
Redis hashes are record types structured as collections of field-value pairs. You can use hashes to represent basic objects and to store groupings of counters, among other things.
```
> HSET user:1 name "Alice" age 25
(integer) 2

> HGET user:1 name
"Alice"

> HGETALL user:1
1) "name"
2) "Alice"
3) "age"
4) "25"

> HMGET user:1 name age no-such-field // multiple get
1) "Alice"
2) "25"
3) (nil)

> HINCRBY user:1 age 1
(integer) 26
> HINCRBY user:1 age -1
(integer) 25

> HINCRBY user:1 score 1
(integer) 1
> HINCRBY user:1 score 1
(integer) 2
> HINCRBY user:1 score 1
(integer) 3

> HMGET user:1 score
1) "3"
```
#### Field expiration 
Redis 7.4 introduced the ability to specify an expiration time or a time-to-live (TTL) value for individual hash fields. This capability is comparable to key expiration and includes a number of similar commands.

Use the following commands to set either an exact expiration time or a TTL value for specific fields:

HEXPIRE: set the remaining TTL in seconds.
HPEXPIRE: set the remaining TTL in milliseconds.
HEXPIREAT: set the expiration time to a timestamp1 specified in seconds.
HPEXPIREAT: set the expiration time to a timestamp specified in milliseconds.
Use the following commands to retrieve either the exact time when or the remaining TTL until specific fields will expire:

HEXPIRETIME: get the expiration time as a timestamp in seconds.
HPEXPIRETIME: get the expiration time as a timestamp in milliseconds.
HTTL: get the remaining TTL in seconds.
HPTTL: get the remaining TTL in milliseconds.
Use the following command to remove the expiration of specific fields:

HPERSIST: remove the expiration.
Redis 8.0 introduced the following commands:

HGETEX: Get the value of one or more fields of a given hash key and optionally set their expiration time or time-to-live (TTL).
HSETEX: Set the value of one or more fields of a given hash key and optionally set their expiration time or time-to-live (TTL).

#### LIMITS: 
Every hash can store up to 4,294,967,295 (2^32 - 1) field-value pairs. In practice, your hashes are limited only by the overall memory on the VMs hosting your Redis deployment.

### 🔸Sorted Sets (VERY IMPORTANT)

A Redis sorted set is a collection of unique strings (members) ordered by an associated score. When more than one string has the same score, the strings are ordered lexicographically. Some use cases for sorted sets include:

Leaderboards. For example, you can use sorted sets to easily maintain ordered lists of the highest scores in a massive online game.
Rate limiters. In particular, you can use a sorted set to build a sliding-window rate limiter to prevent excessive API requests.

```
> ZADD leaderboard  10 "Norem"
(integer) 1
> ZADD leaderboard  12 "Castilla"
(integer) 1
> ZADD leaderboard  8 "Sam-Bodden" 10 "Royce" 6 "Ford" 14 "Prickett"
(integer) 4

> ZRANGE leaderboard 0 -1
1) "Ford"
2) "Sam-Bodden"
3) "Norem"
4) "Royce"
5) "Castilla"
6) "Prickett"

> ZREVRANGE leaderboard 0 -1
1) "Prickett"
2) "Castilla"
3) "Royce"
4) "Norem"
5) "Sam-Bodden"
6) "Ford"
```

Note: 0 and -1 means from element index 0 to the last element (-1 works here just as it does in the case of the LRANGE command).

It is possible to return scores as well, using the WITHSCORES argument:
```
> ZRANGE leaderboard 0 -1 withscores
 1) "Ford"
 2) "6"
 3) "Sam-Bodden"
 4) "8"
 5) "Norem"
 6) "10"
 7) "Royce"
 8) "10"
 9) "Castilla"
10) "12"
11) "Prickett"
12) "14"
```

#### Operating on ranges
Sorted sets are more powerful than this. They can operate on ranges. Let's get all the racers with 10 or fewer points. We use the ZRANGEBYSCORE command to do it:

```
> ZRANGEBYSCORE leaderboard -inf 10
1) "Ford"
2) "Sam-Bodden"
3) "Norem"
4) "Royce"
```

We asked Redis to return all the elements with a score between negative infinity and 10 (both extremes are included).

To remove an element we'd simply call ZREM with the racer's name. It's also possible to remove ranges of elements. Let's remove racer Castilla along with all the racers with strictly fewer than 10 points:

```
> ZREM leaderboard "Castilla"
(integer) 1
> ZREMRANGEBYSCORE leaderboard -inf 9
(integer) 2
> ZRANGE leaderboard 0 -1
1) "Norem"
2) "Royce"
3) "Prickett"
```
Another extremely useful operation defined for sorted set elements is the get-rank operation. It is possible to ask what is the position of an element in the set of ordered elements. The ZREVRANK command is also available in order to get the rank, considering the elements sorted in a descending way.
```

> ZRANK leaderboard "Norem"
(integer) 0
> ZREVRANK leaderboard "Norem"
(integer) 2
```
## ⚡CACHING (REAL PRO UNDERSTANDING)
Cache-Aside (Most used) <br>
flow
```
User → API → Redis → DB
```

## 🚦 RATE LIMITING (REAL SYSTEM DESIGN)

```
INCR user:1
EXPIRE user:1 60 // expair it in 60sec
```

## 📡 PUB/SUB (REAL-TIME SYSTEM)
Example:<br>
Terminal 1:
```
SUBSCRIBE chat
```
Terminal 2:
```
PUBLISH chat "hello"
```
subscriber will receive message from the publisher, only publisher can send the message <br>
👉 Instant message delivery<br>

⚠️ Limitation:<br>
Messages are NOT stored<br>
If subscriber is offline → lost

👉 Solution:<br>
Use Streams

## 🧠 REDIS PERSISTENCE (VERY IMPORTANT)

Redis is NOT just memory — it can persist.

🔸 RDB (Snapshots)
- Saves data every X seconds
- Lightweight

👉 Good for backups

🔸 AOF (Append Only File)
- Logs every write operation

👉 More durable

Best Practice:

Use BOTH

## 🧠 MEMORY MANAGEMENT
Eviction Policies:

When memory is full:

- noeviction
- allkeys-lru (best)
- volatile-lru

👉 LRU = Least Recently Used
