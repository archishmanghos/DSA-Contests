def countPaths(self, n: int, roads: List[List[int]]) -> int:
        d = defaultdict(list)
        for i,j,k in roads:
            d[i].append([j,k])
            d[j].append([i,k])
        
        q,t,c = [[0,0]],float('inf'),0
        v = [float('inf')]*(n)
        while q:
            node,dis = q.pop(0)
            for cnode,cdis in d[node]:
                if cnode==n-1:
                    if cdis+dis==v[cnode]:
                        c+=1
                    elif cdis+dis<v[cnode]:
                        v[cnode] = cdis+dis
                        c=1
                else:
                    if v[cnode]>=dis+cdis:
                        v[cnode] = dis+cdis
                        q.append([cnode,dis+cdis])
        return c