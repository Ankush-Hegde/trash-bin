I’ll explain from zero to production level so you understand how engineers actually use Nginx in microservices.

We will cover:

What Nginx actually is

How routing works

Writing config for user / product / order services

Load balancing

TLS (HTTPS)

Deploying on cloud like

Amazon Web Services

Microsoft Azure

Google Cloud

1. What Nginx Actually Is

Nginx is mainly used for:
```
1️⃣ Web server
2️⃣ Reverse proxy
3️⃣ Load balancer
4️⃣ API gateway (basic)
5️⃣ TLS termination
```
file name can be 
```
nginx.conf
default.conf
gateway.conf
api.conf
```
In microservices it usually acts as:
```
Client
  |
Nginx (Gateway)
  |
----------------------
|        |          |
User   Product    Order
Service Service   Service
```
Client never talks directly to services.

Everything goes through Nginx.

2. Where Nginx Configuration Lives

Main file usually:

/etc/nginx/nginx.conf

or

/etc/nginx/conf.d/default.conf

Structure looks like:
```
events { }

http {

    server {
    }

}
```
Important blocks:
```
events {}
http {}
server {}
location {}
upstream {}
```
3. Reverse Proxy Concept

Nginx forwards request to another service.

Example:

Client → Nginx → user-service:8080

The directive used is:

proxy_pass
4. Your Example Routing

You want:
```
/users/*   → user service
/products/* → product service
/orders/*  → order service
```
Assume services run like:
```
user-service     :5001
product-service  :5002
order-service    :5003
```
Nginx Config
```
http {

    server {
        listen 80;

        location /users/ {
            proxy_pass http://user-service:5001;
        }

        location /products/ {
            proxy_pass http://product-service:5002;
        }

        location /orders/ {
            proxy_pass http://order-service:5003;
        }

    }

}
```
Now request flow:
```
GET /users/1
```
Flow:
```
Client
   |
Nginx
   |
user-service:5001
```
5. Wildcard Routing

If request is:
```
/users/profile
/users/123
/users/settings
```
All will go to user service because:
```
location /users/
```
means:
```
anything starting with /users/
```
6. Real Production Setup (Load Balancing)

Often a service has multiple instances.

Example:
```
User Service
 ├ user1:5001
 ├ user2:5001
 └ user3:5001
```
Define upstream:
```
upstream user_service {

    server user1:5001;
    server user2:5001;
    server user3:5001;

}

Then route:

location /users/ {
    proxy_pass http://user_service;
}
```
Now Nginx automatically load balances.

Default algorithm:
```
Round Robin
```
Example:
```
req1 → user1
req2 → user2
req3 → user3
req4 → user1
```
7. Headers Forwarding (Important)

Real configs include headers:
```
location /users/ {

    proxy_pass http://user_service;

    proxy_set_header Host $host;
    proxy_set_header X-Real-IP $remote_addr;

}
```
Why?

So backend knows:

client IP
original host
8. TLS / HTTPS Setup

TLS encrypts communication.

Instead of:

http://api.example.com

you use:

https://api.example.com

Nginx handles TLS.

This is called TLS termination.

Architecture:
```
Client (HTTPS)
      |
Nginx (decrypt TLS)
      |
Services (HTTP)

Services stay simple.
```

9. Nginx HTTPS Configuration

Example:
```
server {

    listen 443 ssl;

    server_name api.example.com;

    ssl_certificate /etc/ssl/cert.pem;
    ssl_certificate_key /etc/ssl/key.pem;

    location /users/ {
        proxy_pass http://user_service;
    }

}
```
Now traffic is secure.

10. Redirect HTTP → HTTPS

Add this:
```
server {

    listen 80;

    return 301 https://$host$request_uri;

}
```
Flow:
```
http request
   ↓
redirect
   ↓
https request
```
11. Running Nginx

Start service:
```
sudo systemctl start nginx
```
Reload config:
```
sudo nginx -s reload
```
Test config:
```
nginx -t
```
12. Running With Docker (Very Common)

Example docker command:
```
docker run -p 80:80 -v ./nginx.conf:/etc/nginx/nginx.conf nginx
```
Then:
```
Client → container → services
```
13. Using Nginx on Cloud

On cloud platforms like:

=> Amazon Web Services

=> Microsoft Azure

=> Google Cloud

the architecture usually looks like:
```
Internet
   |
Cloud Load Balancer
   |
Nginx (EC2 / VM)
   |
Microservices
```
Example on AWS:
```
Internet
   |
ALB
   |
EC2 (Nginx)
   |
Docker services
```
Steps:

1️⃣ Create VM (EC2 / VM instance)
2️⃣ Install Nginx
```
sudo apt install nginx
```
3️⃣ Put config in
```
/etc/nginx/nginx.conf
```
4️⃣ Open ports:
```
80
443
```
5️⃣ Start Nginx.

14. TLS Certificates in Cloud

Use free certificates from:

Let's Encrypt

Tool:
```
certbot
```
Install:

```
sudo apt install certbot python3-certbot-nginx
```
Generate certificate:

```
sudo certbot --nginx -d api.example.com
```
Certbot automatically configures TLS.

15. Real Production Architecture

Typical modern system:
```
Internet
   |
CDN
   |
Cloud Load Balancer
   |
Nginx Gateway
   |
--------------------------------
|       |        |             |
Auth   User    Product      Order
Svc    Svc      Svc          Svc
```
16. What Nginx Handles in Microservices

Nginx responsibilities:
```
Routing
Reverse proxy
Load balancing
TLS termination
Rate limiting
Compression
Caching
```
17. Your Example Full Config (Clean Version)
```
events {}

http {

    upstream user_service {
        server user1:5001;
        server user2:5001;
    }

    upstream product_service {
        server product1:5002;
    }

    upstream order_service {
        server order1:5003;
    }

    server {

        listen 80;

        location /users/ {
            proxy_pass http://user_service;
        }

        location /products/ {
            proxy_pass http://product_service;
        }

        location /orders/ {
            proxy_pass http://order_service;
        }

    }

}
```

✅ Now Nginx acts as:

```API Gateway
Reverse Proxy
Load Balancer
TLS Terminator
```

If you want, I can also teach you one extremely important thing most backend engineers don't understand well:

How Nginx internally works (event loop, worker processes, epoll, async networking).

That knowledge makes you very strong in backend interviews and system design.