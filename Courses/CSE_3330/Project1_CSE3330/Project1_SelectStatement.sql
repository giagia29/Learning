--GROUP MEMBER: CHERRYL MARIA BIBIN, NINAD PANDIT, GIA DAO

-- PART 2: SQL QUERIES - SELECT STATEMENT

-- Query 3
SELECT	P.NAME, P.SALARY
FROM	Player AS P, Team AS T
WHERE	P.TEAM_ID = T.ID AND T.NAME = "Vegas Golden Knights";

-- Query 4
SELECT	I.INJ_DESC
FROM	InjuryRecord AS I, Player AS P
WHERE	I.PLAYER_ID = P.ID AND P.NAME = "Devan Dubnyk";

-- Query 5
SELECT	CAPTAIN, NAME
FROM	Team

-- Query 6
SELECT		T.NAME, COUNT(P.ID)
FROM		Player AS P, Team AS T
WHERE		P.TEAM_ID = T.ID 
GROUP BY	T.NAME
ORDER BY	COUNT(P.TEAM_ID) DESC;

-- Query 7a
SELECT		T.ID AS Team_ID, T.NAME AS Team_Name, COUNT(G.HOST_TEAM) AS Total_Win
FROM		Team AS T
LEFT JOIN	Game AS G ON G.HOST_TEAM = T.ID AND G.H_T_SCORE > G.G_T_SCORE
GROUP BY	T.NAME
ORDER BY	T.ID ASC;

-- Query 7b
SELECT 		T.ID AS Team_ID, T.NAME AS Team_Name, COUNT(G.HOST_TEAM) AS Total_Loss
FROM 		Team AS T
LEFT JOIN 	Game AS G ON G.HOST_TEAM = T.ID AND G.H_T_SCORE < G.G_T_SCORE
GROUP BY 	T.NAME
ORDER BY 	T.ID ASC;