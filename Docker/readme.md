# 🐳 What Docker Actually Is (Deep Level)

Docker is an open platform for developing, shipping, and running applications. Docker enables you to separate your applications from your infrastructure so you can deliver software quickly. With Docker, you can manage your infrastructure in the same ways you manage your applications. By taking advantage of Docker's methodologies for shipping, testing, and deploying code, you can significantly reduce the delay between writing code and running it in production.

Docker is containerization using OS-level virtualization.

🔥 Key idea most people miss:

Docker does NOT run a full OS like a VM.

Instead it uses:

Namespaces → isolate processes
cgroups → limit CPU/RAM
Union File System (OverlayFS) → layered filesystem

👉 So containers are:

Just isolated processes on your host OS

### What can I use Docker for?
#### Fast, consistent delivery of your applications
Docker streamlines the development lifecycle by allowing developers to work in standardized environments using local containers which provide your applications and services. Containers are great for continuous integration and continuous delivery (CI/CD) workflows.

Consider the following example scenario:

- Your developers write code locally and share their work with their colleagues using Docker containers.
- They use Docker to push their applications into a test environment and run automated and manual tests.
- When developers find bugs, they can fix them in the development environment and redeploy them to the test environment for testing and validation.
- When testing is complete, getting the fix to the customer is as simple as pushing the updated image to the production environment.

#### Responsive deployment and scaling
Docker's container-based platform allows for highly portable workloads. Docker containers can run on a developer's local laptop, on physical or virtual machines in a data center, on cloud providers, or in a mixture of environments.

Docker's portability and lightweight nature also make it easy to dynamically manage workloads, scaling up or tearing down applications and services as business needs dictate, in near real time.

#### Running more workloads on the same hardware
Docker is lightweight and fast. It provides a viable, cost-effective alternative to hypervisor-based virtual machines, so you can use more of your server capacity to achieve your business goals. Docker is perfect for high density environments and for small and medium deployments where you need to do more with fewer resources.

### 🧠 Image vs Container (REAL understanding)
docker image is build and docker image can create a docker container.
![image-vs-container](image-vs-container.png)

👉 Flow:
```
Dockerfile → Image → Container
```

# 🧱 Docker Architecture

Docker uses a client-server architecture. The Docker client talks to the Docker daemon, which does the heavy lifting of building, running, and distributing your Docker containers. The Docker client and daemon can run on the same system, or you can connect a Docker client to a remote Docker daemon. The Docker client and daemon communicate using a REST API, over UNIX sockets or a network interface. Another Docker client is Docker Compose, that lets you work with applications consisting of a set of containers.

#### Components:

- Docker Client (docker)
- Docker Daemon (dockerd)
- Registry (like Docker Hub)
- Docker objects
    - Images (layered)
    - Containers

![docker-architecture](docker-architecture.png)

#### The Docker client
The Docker client (docker) is the primary way that many Docker users interact with Docker. When you use commands such as docker run, the client sends these commands to dockerd, which carries them out. The docker command uses the Docker API. The Docker client can communicate with more than one daemon.

#### The Docker daemon
The Docker daemon (dockerd) listens for Docker API requests and manages Docker objects such as images, containers, networks, and volumes. A daemon can also communicate with other daemons to manage Docker services.

#### Docker registries
A Docker registry stores Docker images. Docker Hub is a public registry that anyone can use, and Docker looks for images on Docker Hub by default. You can even run your own private registry.

When you use the docker pull or docker run commands, Docker pulls the required images from your configured registry. When you use the docker push command, Docker pushes your image to your configured registry.

#### Docker objects
When you use Docker, you are creating and using images, containers, networks, volumes, plugins, and other objects. This section is a brief overview of some of those objects.

##### Images
An image is a read-only template with instructions for creating a Docker container. Often, an image is based on another image, with some additional customization. For example, you may build an image that is based on the Ubuntu image but includes the Apache web server and your application, as well as the configuration details needed to make your application run.

You might create your own images or you might only use those created by others and published in a registry. To build your own image, you create a Dockerfile with a simple syntax for defining the steps needed to create the image and run it. Each instruction in a Dockerfile creates a layer in the image. When you change the Dockerfile and rebuild the image, only those layers which have changed are rebuilt. This is part of what makes images so lightweight, small, and fast, when compared to other virtualization technologies.

##### Containers
A container is a runnable instance of an image. You can create, start, stop, move, or delete a container using the Docker API or CLI. You can connect a container to one or more networks, attach storage to it, or even create a new image based on its current state.

By default, a container is relatively well isolated from other containers and its host machine. You can control how isolated a container's network, storage, or other underlying subsystems are from other containers or from the host machine.

A container is defined by its image as well as any configuration options you provide to it when you create or start it. When a container is removed, any changes to its state that aren't stored in persistent storage disappear.

Example ```docker run``` command

The following command runs an ubuntu container, attaches interactively to your local command-line session, and runs ```/bin/bash.```


```docker run -i -t ubuntu /bin/bash```

When you run this command, the following happens (assuming you are using the default registry configuration):

- If you don't have the ```ubuntu``` image locally, Docker pulls it from your configured registry, as though you had run ```docker pull ubuntu``` manually.

- Docker creates a new container, as though you had run a ```docker container create``` command manually.

- Docker allocates a read-write filesystem to the container, as its final layer. This allows a running container to create or modify files and directories in its local filesystem.

- Docker creates a network interface to connect the container to the default network, since you didn't specify any networking options. This includes assigning an IP address to the container. By default, containers can connect to external networks using the host machine's network connection.

- Docker starts the container and executes ```/bin/bash.``` Because the container is running interactively and attached to your terminal (due to the ```-i``` and ```-t``` flags), you can provide input using your keyboard while Docker logs the output to your terminal.

- When you run ```exit``` to terminate the ```/bin/bash``` command, the container stops but isn't removed. You can start it again or remove it.

<details><summary> Containerd
</summary>

<dev>

containerd is a lightweight, high-performance container runtime originally developed by Docker and now maintained by the Cloud Native Computing Foundation.

It is responsible for:

- Pulling container images
- Managing container lifecycle (start, stop, pause, delete)
- Handling storage & networking (via plugins)
- Running containers using OS features (namespaces, cgroups)

##### 🔹 Where containerd fits (Big Picture)

Think of the stack like this:
```
Kubernetes
   ↓
container runtime (containerd)
   ↓
Linux Kernel (namespaces, cgroups)
```
Or in Docker:
```
Docker CLI
   ↓
Docker Engine
   ↓
containerd
   ↓
runc
   ↓
Linux Kernel
```
👉 Important:
- Docker uses containerd internally
- Kubernetes can use containerd directly (without Docker)

🔹 Key Components inside containerd
1. Image Management
    - Pulls images from registries (Docker Hub, etc.)
    - Stores images locally
2. Container Lifecycle
    - Create → Start → Stop → Delete containers
3. Snapshotters
    - Manage filesystem layers (overlayfs, btrfs, etc.)
4. Runtime (runc)
    - Uses runc to actually spawn containers

<dev>
</details>

|==================================================================|

#### What you'll learn
- Run your first container
- Build your first image
- Publish your image on Docker Hub

#### Modules
##### 1. Run your first container<br>
Open your CLI terminal and start a container by running the docker run command:
```
docker run -d -p 8080:80 docker/welcome-to-docker
```
<details>
<summary>Explaination</summary>
<dev>

```
🔹docker run

This is the command to create and start a container from an image.

If the image doesn’t exist locally, Docker will pull it from Docker Hub automatically.
Then it creates a container and runs it.

🔹-d (detached mode)

This tells Docker to run the container in the background.

Without -d: logs appear in your terminal and block it
With -d: container runs silently, and you get your terminal back

👉 Think: “run it as a background service”

🔹-p 8080:80 (port mapping)

This maps ports between your machine and the container.

Format:

-p <host_port>:<container_port>

So here:

8080 → your local machine (host)
80 → inside the container

👉 Meaning:
When you open:

http://localhost:8080

it forwards traffic to:

container:80
🔹docker/welcome-to-docker

This is the image name.

It’s hosted on Docker Hub
It’s a simple web app that runs on port 80 inside the container

```

</dev>
</details>

Access the frontend
For this container, the frontend is accessible on port 8080. To open the website, visit http://localhost:8080 in your browser.

<details>
<summary>🔥 Extra useful commands</summary>

<dev>

Check running containers:
```
docker ps
```
Stop the container:
```
docker stop <container_id>
```
View logs:
```
docker logs <container_id>
```

</dev>
</details>

<details> <summary>
Develop with containers
</summary>

<dev> 

- You can have a docker compose file which will have multiple config for application’s services.
- run ``` docker compose watch ``` and make a changes to the required files in the project and save, that will be reflected.

</dev>
</details>

</details>

<details> <summary>
Build and push your first image
</summary>

<dev> 

1. To get started, either clone or download the project as a ZIP file to your local machine.

```
 git clone https://github.com/docker/getting-started-todo-app
 ```
And after the project is cloned, navigate into the new directory created by the clone:
```
 cd getting-started-todo-app
```
2. Build the project by running the following command, swapping out ```DOCKER_USERNAME``` with your username.
```
 docker build -t DOCKER_USERNAME/getting-started-todo-app .
```
For example, if your Docker username was ```mobydock```, you would run the following:
```
 docker build -t mobydock/getting-started-todo-app .
```
To verify the image exists locally, you can use the ```docker image ls``` command:
```
 docker image ls
```
You will see output similar to the following:
```
REPOSITORY                          TAG       IMAGE ID       CREATED          SIZE
mobydock/getting-started-todo-app   latest    1543656c9290   2 minutes ago    1.12GB
...
```
To push the image, use the ```docker push``` command. Be sure to replace ```DOCKER_USERNAME``` with your username:
```
 docker push DOCKER_USERNAME/getting-started-todo-app
```
Depending on your upload speeds, this may take a moment to push.

</dev>
</details>