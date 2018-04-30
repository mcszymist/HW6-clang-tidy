-- PA5.hs  UNFINISHED
-- Tyler J Roberts
-- 17 Mar 2017
--
-- For CS F331 / CSCE A331 Spring 2017
-- Solutions to Assignment 5 Exercise B

module PA5 where
import Data.List

-- collatzCounts Function Bundle but cant get it to work with take
-- Takes a list of Ints and gives the number of steps for the collatz algorithm to finish
-- returns a list
collatzCounts :: [Int]->[Int]
collatzCounts n = reverse(collatzTuple([],n))

collatzTuple :: ([Int],[Int])->[Int]
collatzTuple (a, b) | null b = a
                    | otherwise = collatzTuple(length(collatzArray(head b))-1:a,tail b)
                  
collatzArray :: Int->[Int] --brackets means array
collatzArray n | n <= 0    = error "N must be positive"
               | n == 1    = 1 : [] 
               | otherwise = n : collatzArray (collatz n) -- recusive call
			   
collatz :: Int -> Int
collatz n | even n    = n `div` 2
          | otherwise = 3 * n + 1

-- findList
-- Takes two lists and trys to find if lists a is in list b and where at its located.
-- returns a maybe Int
findList :: Eq a => [a] -> [a] -> Maybe Int
findList lista listb | isInfixOf lista listb == True = elemIndex (head lista) listb
                     | otherwise = Nothing

-- op ##
-- op that takes one before and after it; filters the list by what the have in common.
-- returns a Int
(##) :: Eq a => [a] -> [a] -> Int
a ## b = length(filter(`elem` a)b)


-- filterAB -- Not Done
filterAB :: (a -> Bool) -> [a] -> [b] -> [b]
filterAB func lista listb = listb  -- ??? every thing I did the types wouldnt match


