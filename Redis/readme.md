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

