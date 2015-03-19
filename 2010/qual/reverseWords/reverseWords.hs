
reversehelper :: String -> (String, String)
reversehelper "" = ("", "")
reversehelper (x:xs) 
  | x == ' ' = ("", xs)
  | otherwise = (x:ys, zs)
   where (ys, zs) = reversehelper xs

reverseWords :: String -> String
reverseWords "" = ""
reverseWords x = reverseWords zs ++ ((\ y -> if null y then "" else " ") zs) ++ ys
  where (ys, zs) = reversehelper x

main = do
     n <- readLn :: IO Int
     contents <- getContents
     mapM_ putStrLn (map reverseWords (lines contents))
