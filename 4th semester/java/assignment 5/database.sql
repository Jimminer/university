-- MariaDB dump 10.19  Distrib 10.11.2-MariaDB, for Linux (aarch64)
--
-- Host: localhost    Database: library
-- ------------------------------------------------------
-- Server version	10.11.2-MariaDB

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `authors`
--

DROP TABLE IF EXISTS `authors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `authors` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `firstName` varchar(255) NOT NULL,
  `lastName` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `authors`
--

LOCK TABLES `authors` WRITE;
/*!40000 ALTER TABLE `authors` DISABLE KEYS */;
INSERT INTO `authors` VALUES
(1,'Jack','Jones'),
(2,'Michael','Peterson'),
(3,'Keanu','Reeves'),
(4,'Martin Luther','King'),
(5,'Rick','Astley'),
(6,'Anna','Frank'),
(7,'Benjamin','White'),
(8,'Ava','Max'),
(9,'Drake','Josh'),
(10,'Pablo','Escobar');
/*!40000 ALTER TABLE `authors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bookAuthors`
--

DROP TABLE IF EXISTS `bookAuthors`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookAuthors` (
  `isbn` int(11) NOT NULL,
  `authorId` int(11) NOT NULL,
  PRIMARY KEY (`isbn`,`authorId`),
  KEY `bookAuthors_ibfk_2` (`authorId`),
  CONSTRAINT `bookAuthors_ibfk_1` FOREIGN KEY (`isbn`) REFERENCES `books` (`isbn`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `bookAuthors_ibfk_2` FOREIGN KEY (`authorId`) REFERENCES `authors` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookAuthors`
--

LOCK TABLES `bookAuthors` WRITE;
/*!40000 ALTER TABLE `bookAuthors` DISABLE KEYS */;
INSERT INTO `bookAuthors` VALUES
(1,1),
(1,2),
(1,3),
(2,4),
(2,5),
(3,6),
(4,7),
(4,8),
(4,9),
(5,10),
(6,1),
(6,2),
(7,3),
(7,4),
(7,5),
(8,6),
(8,7),
(8,8),
(9,9),
(10,1),
(10,10);
/*!40000 ALTER TABLE `bookAuthors` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `bookReservations`
--

DROP TABLE IF EXISTS `bookReservations`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `bookReservations` (
  `isbn` int(11) NOT NULL,
  `userId` int(11) NOT NULL,
  `timeReserved` timestamp NOT NULL,
  PRIMARY KEY (`isbn`,`userId`,`timeReserved`),
  KEY `userId` (`userId`),
  CONSTRAINT `bookReservations_ibfk_1` FOREIGN KEY (`isbn`) REFERENCES `books` (`isbn`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `bookReservations_ibfk_2` FOREIGN KEY (`userId`) REFERENCES `users` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `bookReservations`
--

LOCK TABLES `bookReservations` WRITE;
/*!40000 ALTER TABLE `bookReservations` DISABLE KEYS */;
INSERT INTO `bookReservations` VALUES
(1,2,'2023-06-11 13:03:56'),
(2,1,'2023-05-12 12:55:34'),
(2,1,'2023-06-11 13:03:33');
/*!40000 ALTER TABLE `bookReservations` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `books`
--

DROP TABLE IF EXISTS `books`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `books` (
  `isbn` int(11) NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `year` int(11) DEFAULT NULL,
  `description` text DEFAULT NULL,
  PRIMARY KEY (`isbn`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `books`
--

LOCK TABLES `books` WRITE;
/*!40000 ALTER TABLE `books` DISABLE KEYS */;
INSERT INTO `books` VALUES
(1,'A Great Title',2023,'A story about a great title.'),
(2,'Harry Potter',3251,'You\'re a wizard Harry.'),
(3,'Bad Book',-700,'An old bad book.'),
(4,'Imagination',2004,'Not interesting.'),
(5,'Odyssey',-800,'A stupid book we had to learn in high school.'),
(6,'The Lord of the Rings X',2042,'Ring.'),
(7,'Pacman the book',2000,'I\'m bored.'),
(8,'True Story',1990,'Definitely not a true story.'),
(9,'The last book',2004,'Could it be the end?'),
(10,'Ok for real now',1950,'Finally.');
/*!40000 ALTER TABLE `books` ENABLE KEYS */;
UNLOCK TABLES;

--
-- Table structure for table `users`
--

DROP TABLE IF EXISTS `users`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `users` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `username` varchar(255) DEFAULT NULL,
  `password` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`id`),
  UNIQUE KEY `username` (`username`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `users`
--

LOCK TABLES `users` WRITE;
/*!40000 ALTER TABLE `users` DISABLE KEYS */;
INSERT INTO `users` VALUES
(1,'cs04502@uowm.gr','1234'),
(2,'cs04557@uowm.gr','1234'),
(3,'ndimokas@uowm.gr','1234');
/*!40000 ALTER TABLE `users` ENABLE KEYS */;
UNLOCK TABLES;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2023-06-11 18:51:18
