
---

### 19. `data/gen_data.py`
```python
import numpy as np
import pandas as pd

def simulate_rssi(num_samples=1000, anchors=4):
    positions = np.random.uniform(-500,500,(num_samples,2))
    anchor_pos = np.array([[0,0],[100,0],[0,100],[100,100]])
    rows = []
    for p in positions:
        d = np.linalg.norm(anchor_pos - p, axis=1)
        r = -20*np.log10(d+1) + np.random.normal(0,2,size=anchors)
        rows.append(np.concatenate((p, r)))
    df = pd.DataFrame(
        rows,
        columns=["x","y"] + [f"rssi_{i}" for i in range(anchors)]
    )
    df.to_csv("data/sample_rssi.csv", index=False)
    print("Wrote data/sample_rssi.csv")

if __name__ == "__main__":
    simulate_rssi()
