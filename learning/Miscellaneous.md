So this happened `5858317 (HEAD -> develop) Merge branch 'develop' of https://github.com/Solmelu/backend into develop`


As you can see the develop branch gets merged into itself.
When does it happen?

Basically let's say the commit history in your local repo of the branch is different than the commit history of the remote repo and then if you do a git pull .

Git will merge these commits and this commit message appears