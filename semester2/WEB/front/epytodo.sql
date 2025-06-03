CREATE DATABASE IF NOT EXISTS epytodo;

USE epytodo;

CREATE TABLE IF NOT EXISTS user (
    id         INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    email      VARCHAR(255) NOT NULL,
    password   VARCHAR(255) NOT NULL,
    name       VARCHAR(255) NOT NULL,
    firstname  VARCHAR(255) NOT NULL,
    created_at DATETIME DEFAULT(NOW()) NOT NULL
);

CREATE TABLE IF NOT EXISTS todo (
    id          INT NOT NULL AUTO_INCREMENT PRIMARY KEY,
    title       VARCHAR(255) NOT NULL,
    description VARCHAR(255) NOT NULL,
    due_time    DATETIME NOT NULL,
    status      ENUM('not started', 'todo', 'in progress', 'done') DEFAULT 'not started' NOT NULL,
    user_id     INT NOT NULL,
    FOREIGN KEY (user_id) REFERENCES user(id),
    created_at  DATETIME DEFAULT(NOW()) NOT NULL
);
