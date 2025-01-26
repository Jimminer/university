BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS "University" (
	"name"	TEXT NOT NULL,
	"address"	TEXT,
	"city"	TEXT,
	"description"	TEXT,
	PRIMARY KEY("name")
);
CREATE TABLE IF NOT EXISTS "Department" (
	"depId"	INTEGER NOT NULL,
	"name"	TEXT,
	"address"	TEXT,
	"receptionPhone"	TEXT,
	"email"	TEXT,
	"city"	TEXT,
	"universityName"	TEXT NOT NULL,
	PRIMARY KEY("depId"),
	FOREIGN KEY("universityName") REFERENCES "University"("name")
);
CREATE TABLE IF NOT EXISTS "Professor" (
	"empId"	INTEGER NOT NULL,
	"firstName"	TEXT,
	"lastName"	TEXT,
	"address"	TEXT,
	"birthDate"	TEXT,
	"rank"	TEXT,
	"doctorateDuration"	INTEGER,
	"mastersCount"	INTEGER,
	"postCount"	INTEGER,
	"depId"	INTEGER NOT NULL,
	PRIMARY KEY("empId"),
	FOREIGN KEY("depId") REFERENCES "Department"("depId")
);
CREATE TABLE IF NOT EXISTS "HeadEmployee" (
	"empId"	INTEGER NOT NULL,
	"firstName"	TEXT,
	"lastName"	TEXT,
	"address"	TEXT,
	"birthDate"	TEXT,
	"SSN"	TEXT,
	"dutyYears"	INTEGER,
	"monthlySalary"	INTEGER,
	"specialty"	TEXT,
	"depId"	INTEGER NOT NULL,
	FOREIGN KEY("depId") REFERENCES "Department"("depId"),
	PRIMARY KEY("empId")
);
CREATE TABLE IF NOT EXISTS "PostDegree" (
	"stuId"	INTEGER NOT NULL,
	"firstName"	TEXT,
	"lastName"	TEXT,
	"birthDate"	TEXT,
	"homeCity"	TEXT,
	"degreeTitle"	TEXT,
	"degreeGrade"	REAL,
	"thesisTitle"	TEXT,
	"depId"	INTEGER NOT NULL,
	FOREIGN KEY("depId") REFERENCES "Department"("depId"),
	PRIMARY KEY("stuId")
);
CREATE TABLE IF NOT EXISTS "PreDegree" (
	"stuId"	INTEGER NOT NULL,
	"firstName"	TEXT,
	"lastName"	TEXT,
	"birthDate"	TEXT,
	"homeCity"	TEXT,
	"enrollYear"	INTEGER,
	"avgGrade"	REAL,
	"depId"	INTEGER NOT NULL,
	PRIMARY KEY("stuId"),
	FOREIGN KEY("depId") REFERENCES "Department"("depId")
);
CREATE TABLE IF NOT EXISTS "Student" (
	"stuId"	INTEGER NOT NULL,
	"preDegreeId"	INTEGER,
	"postDegreeId"	INTEGER,
	PRIMARY KEY("stuId"),
	FOREIGN KEY("postDegreeId") REFERENCES "PostDegree"("stuId"),
	FOREIGN KEY("preDegreeId") REFERENCES "PreDegree"("stuId")
);
CREATE TABLE IF NOT EXISTS "Subject" (
	"subId"	INTEGER NOT NULL,
	"name"	TEXT,
	"description"	TEXT,
	"profId"	INTEGER NOT NULL,
	FOREIGN KEY("profId") REFERENCES "Professor"("empId"),
	PRIMARY KEY("subId")
);
CREATE TABLE IF NOT EXISTS "StudentSubjects" (
	"stuId"	INTEGER NOT NULL,
	"subId"	INTEGER NOT NULL,
	"grade"	INTEGER,
	FOREIGN KEY("subId") REFERENCES "Subject"("subId"),
	FOREIGN KEY("stuId") REFERENCES "Student"("stuId"),
	PRIMARY KEY("stuId","subId")
);

INSERT INTO "University" VALUES ('UOWM','UOWM Address','Kastoria','Panepistimio kastorias');
INSERT INTO "University" VALUES ('AUTH','AUTH Address','Thessaloniki','Panepistimio thessalonikis');
INSERT INTO "Department" VALUES (1,'Informatics','Megalo ktirio','2467012345','informatics@uowm.gr','Kastoria','UOWM');
INSERT INTO "Department" VALUES (2,'Physics','Mikro ktirio','2467054321','physics@uowm.gr','Kastoria','UOWM');
INSERT INTO "Department" VALUES (3,'Informatics','Megalo ktirio 2','2311234567','informatics@auth.gr','Thessaloniki','AUTH');
INSERT INTO "Department" VALUES (4,'Physics','Mikro ktirio 2','2317654321','physics@auth.gr','Thessaloniki','AUTH');
INSERT INTO "PostDegree" VALUES (2,'Antonis','Papadopoulos','15-2-1999','Thessaloniki','Quantum Physics',9.8,'Quantum Particles',1);
INSERT INTO "PostDegree" VALUES (4,'Marios','Papadopoulos','19-5-1982','Kalamata','Farmer Physics',1.2,'How to open a glass bottle',2);
INSERT INTO "PostDegree" VALUES (6,'Filipos','Papadopoulos','15-2-1999','Thessaloniki','Quantum Physics',9.8,'Quantum Particles',3);
INSERT INTO "PostDegree" VALUES (8,'Giorgos','Papadopoulos','19-5-1982','Kalamata','Farmer Physics',1.2,'How to open a glass bottle',4);
INSERT INTO "PreDegree" VALUES (1,'Giannis','Papadopoulos','1-1-2003','Athens',2021,3.5,1);
INSERT INTO "PreDegree" VALUES (3,'Kostas','Papadopoulos','7-5-2003','Athens',2022,5.5,2);
INSERT INTO "PreDegree" VALUES (5,'Apolonas','Papadopoulos','1-1-2003','Athens',2021,3.5,3);
INSERT INTO "PreDegree" VALUES (7,'Spiros','Papadopoulos','7-5-2003','Athens',2022,5.5,4);
INSERT INTO "Professor" VALUES (1,'Marios','Papas','Big house 1','15-6-1966','Platinum',5,8,32,1);
INSERT INTO "Professor" VALUES (2,'Spiros','Papas','Small house 1','15-6-1966','Silver',5,8,32,1);
INSERT INTO "Professor" VALUES (3,'Dimitris','Papas','Big house 2','15-6-1966','Diamond',5,8,32,2);
INSERT INTO "Professor" VALUES (4,'Giannis','Papas','Small house 2','15-6-1966','Gold',5,8,32,2);
INSERT INTO "Professor" VALUES (5,'Paris','Papas','Big house 3','15-6-1966','Gold',5,8,32,3);
INSERT INTO "Professor" VALUES (6,'Xristos','Papas','Small house 3','15-6-1966','Grandmaster',5,8,32,3);
INSERT INTO "Professor" VALUES (7,'Vasilis','Papas','Big house 4','15-6-1966','Gold',5,8,32,4);
INSERT INTO "Professor" VALUES (8,'Anastasis','Papas','Small house 4','15-6-1966','Iron',5,8,32,4);
INSERT INTO "Student" VALUES (1,1,NULL);
INSERT INTO "Student" VALUES (2,NULL,2);
INSERT INTO "Student" VALUES (3,3,NULL);
INSERT INTO "Student" VALUES (4,NULL,4);
INSERT INTO "Student" VALUES (5,5,NULL);
INSERT INTO "Student" VALUES (6,NULL,6);
INSERT INTO "Student" VALUES (7,7,NULL);
INSERT INTO "Student" VALUES (8,NULL,8);
INSERT INTO "Subject" VALUES (1,'Subject 1','Description 1',1);
INSERT INTO "Subject" VALUES (2,'Subject 2','Description 2',1);
INSERT INTO "Subject" VALUES (3,'Subject 3','Description 3',2);
INSERT INTO "Subject" VALUES (4,'Subject 4','Description 4',2);
INSERT INTO "Subject" VALUES (5,'Subject 5','Description 5',3);
INSERT INTO "Subject" VALUES (6,'Subject 6','Description 6',3);
INSERT INTO "Subject" VALUES (7,'Subject 7','Description 7',4);
INSERT INTO "Subject" VALUES (8,'Subject 8','Description 8',4);
INSERT INTO "Subject" VALUES (9,'Subject 9','Description 9',5);
INSERT INTO "Subject" VALUES (10,'Subject 10','Description 10',5);
INSERT INTO "Subject" VALUES (11,'Subject 11','Description 11',6);
INSERT INTO "Subject" VALUES (12,'Subject 12','Description 12',6);
INSERT INTO "Subject" VALUES (13,'Subject 13','Description 13',7);
INSERT INTO "Subject" VALUES (14,'Subject 14','Description 14',7);
INSERT INTO "Subject" VALUES (15,'Subject 15','Description 15',8);
INSERT INTO "Subject" VALUES (16,'Subject 16','Description 16',8);
INSERT INTO "StudentSubjects" VALUES (1,1,5);
INSERT INTO "StudentSubjects" VALUES (2,3,5);
INSERT INTO "StudentSubjects" VALUES (3,2,5);
INSERT INTO "StudentSubjects" VALUES (4,1,5);
INSERT INTO "StudentSubjects" VALUES (5,7,5);
INSERT INTO "StudentSubjects" VALUES (6,13,5);
INSERT INTO "StudentSubjects" VALUES (7,10,5);
INSERT INTO "StudentSubjects" VALUES (8,5,5);
COMMIT;
